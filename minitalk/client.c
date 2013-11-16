#include <stdio.h>
#include <minitalk_common.h>
#include <my.h>

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
            if(!send_msg(server_pid, buff))
                putline("Error while sending message");
            buff[0] = 0;
        }
    }
    return (0);
}