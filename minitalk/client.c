#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <minitalk_common.h>
#include <my.h>

void send_msg(pid_t pid, char* msg)
{
    int i;
    int bit_ind;
    int bit;
    int res;

    i = 0;
    while ((msg[i] && i == 0) || msg[i - 1])
    {
        bit_ind = 7;
        while (bit_ind >= 0)
        {
            bit = get_bit_at(msg[i], bit_ind);
            if(bit == 0)
                res = kill(pid, SIGUSR1);
            else
                res = kill(pid, SIGUSR2);
            if(res != 0)
                putline("error sending signal");
            bit_ind--;
            usleep(10);
        }
        i++;
    }
}

int main(int argc, char** argv)
{
    char buff[4096];
    pid_t server_pid;

    if(argc < 2)
        return (0);
    server_pid = my_getnbr(argv[1]);
    while(42)
    {
        my_putstr("$>");
        if(fgets (buff, 4096, stdin) != NULL)
        {
            my_putstr(buff);
            send_msg(server_pid, buff);
            buff[0] = 0;
        }
    }
    return (0);
}