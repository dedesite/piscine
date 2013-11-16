#include <stdlib.h>
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

/**
** Append a bit to a buffered string (one per pid) which is display
** when a null char is detected
*/
void append_bit_to_display(pid_t pid, int bit)
{
    static t_list* l = 0;
    t_bit_msg* msg;

    msg = find_or_add_msg(pid, &l);
    if(bit == 1)
        msg->c = (msg->c << 1) | 0x01;
    else
        msg->c = (msg->c << 1);
    msg->nb_bits++;
    if(msg->nb_bits >= 8)
    {
        msg->buffer[msg->current_ind] = msg->c;
        msg->nb_bits = 0;
        msg->c = 0;
        if(msg->buffer[msg->current_ind] == '\0')
        {
            my_put_nbr(pid);
            my_putstr(" says : ");
            putline(msg->buffer);
            msg->current_ind = 0;
        }
        else
        {
            msg->current_ind++;
        }
    }
}