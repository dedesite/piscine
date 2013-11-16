#include <sys/types.h>
#include <signal.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <my.h>
#include <minitalk_common.h>

/** Return a char bit at a given position*/
int get_bit_at(char c, int pos)
{
    return ((c >> pos) & 1);
}

t_list* add_client(pid_t pid, t_list* l)
{
    t_bit_msg* msg;

    msg = malloc(sizeof(t_bit_msg));
    msg->pid = pid;
    msg->nb_bits = 0;
    msg->current_ind = 0;
    msg->c = 0;
    l = add_in_list(msg, l);
    return (l);
}

t_bit_msg* find_msg(pid_t pid, t_list* l)
{
    t_bit_msg* msg;
    while(l)
    {
        msg = (t_bit_msg*)l->data;
        if(msg->pid == pid)
            return (msg);
        l = l->next;
    }
    return (0);
}

t_bit_msg* find_or_add_msg(pid_t pid, t_list** l)
{
    t_bit_msg* msg;

    msg = find_msg(pid, *l);
    if(msg == 0)
    {
        *l = add_client(pid, *l);
        msg = (t_bit_msg*)(*l)->data;
    }
    return (msg);
}

char append_bit_to_char(char c, int bit)
{
    if(bit == 1)
        c = (c << 1) | 0x01;
    else
        c = (c << 1);
    return (c);
}

/**
** Some message might have been not entirely transfert (lack of '\0' at the end)
** And are pending to be display
*/
void treat_pending_msg(t_list* l, time_t now)
{
    t_bit_msg* msg;

    while(l)
    {
        msg = (t_bit_msg*)l->data;
        if((msg->nb_bits != 0 && msg->current_ind != 0) && now - msg->last_time > 1)
        {
            msg->buffer[msg->current_ind+1] = '\0';
            my_put_nbr(msg->pid);
            my_putstr(":(scramble message)");
            my_putstr(msg->buffer);
            putline("");
            msg->nb_bits = 0;
            msg->c = 0;
            msg->current_ind = 0;
        }
        l = l->next;
    }
}
/**
** Append a bit to a buffered string (one per pid) which is display
** when a null char is detected
*/
void append_bit_to_display(pid_t pid, int bit)
{
    static t_list* l = 0;
    t_bit_msg* msg;
    time_t now;

    time(&now);
    treat_pending_msg(l, now);
    msg = find_or_add_msg(pid, &l);
    msg->c = append_bit_to_char(msg->c, bit);
    msg->last_time = now;
    msg->nb_bits++;
    if(msg->nb_bits >= 8)
    {
        msg->buffer[msg->current_ind] = msg->c;
        msg->nb_bits = 0;
        msg->c = 0;
        if(msg->buffer[msg->current_ind] == '\0')
        {
            my_put_nbr(pid);
            my_putstr(":");
            my_putstr(msg->buffer);
            msg->current_ind = 0;
        }
        else
        {
            msg->current_ind++;
        }
    }
}

/**
** Si tout se passe bien renvoie 1, sinon renvoie 0
*/
int send_char(pid_t pid, char c)
{
    int i;
    int bit;
    int res;

    i = 7;
    while(i >= 0)
    {
        bit = get_bit_at(c, i);
        if(bit == 0)
            res = kill(pid, SIGUSR1);
        else
            res = kill(pid, SIGUSR2);
        if(res != 0)
            return (0);
        i--;
        usleep(10);
    }
    return (1);
}

/**
** Send also the null caracter
**/
int send_msg(pid_t pid, char* msg)
{
    int i;
    int len;

    len = my_strlen(msg);
    i = 0;
    while (i <= len)
    {
        if(!send_char(pid, msg[i]))
            return(0);
        i++;
    }
    return (1);
}