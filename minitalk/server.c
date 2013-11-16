#include <stdlib.h>
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

/**
** Cette fonction fait un bête malloc(1) et le free car j'avais des problèmes
** a la connection du premier client. Je manquais à chaque fois un signal
** et ca décalait tout. Après des heures de debug, j'ai compris que la premier
** malloc d'un programme prenait plus de temps que les autres et donc
** qu'on manquait un signal la première fois...
** C'est crade mais ça fonctionne...
** J'ai géré ce type d'erreur grave à treat_pending_msg mais je préfère
** laisser l'init comme ça on a pas l'erreur au début
**
*/
void init()
{
    char* c = malloc(1);
    free(c);    
}

int main()
{
    struct sigaction act;

    init();
    act.sa_sigaction = &recieve;
    act.sa_flags = SA_SIGINFO;
    if(sigaction(SIGUSR1, &act, NULL) < 0)
        putline("Can't catch SIGUSR1");
    if(sigaction(SIGUSR2, &act, NULL) < 0)
        putline("Can't catch SIGUSR2");
    my_put_nbr(getpid());
    my_putchar('\n');
    while(42)
    {
        pause();
    }
    return (0);
}