#include <signal.h>
#include <unistd.h>
#include <minitalk_common.h>
#include <my.h>

void recieve(int sig)
{
    if(sig == SIGUSR1)
        append_bit_to_display(0);
    else
        append_bit_to_display(1);
}

int main()
{
    if(signal(SIGUSR1, recieve) == SIG_ERR)
        putline("Can't catch SIGUSR1");
    if(signal(SIGUSR2, recieve) == SIG_ERR)
        putline("Can't catch SIGUSR2");
    my_put_nbr(getpid());
    while(42)
    {
        pause();
    }
    return (0);
}