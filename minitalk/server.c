#include <signal.h>
#include <unistd.h>
#include <minitalk_common.h>
#include <my.h>

void recieve(int sig, siginfo_t *siginfo, void *context)
{
    (void)(context);
    if(sig == SIGUSR1)
        append_bit_to_display(siginfo->si_pid, 0);
    else
        append_bit_to_display(siginfo->si_pid, 1);
}

int main()
{
    struct sigaction act;

    act.sa_sigaction = &recieve;
    act.sa_flags = SA_SIGINFO;
    if(sigaction(SIGUSR1, &act, NULL) < 0)
        putline("Can't catch SIGUSR1");
    if(sigaction(SIGUSR2, &act, NULL) < 0)
        putline("Can't catch SIGUSR2");
    my_put_nbr(getpid());
    while(42)
    {
        pause();
    }
    return (0);
}