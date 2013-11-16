#ifndef MINITALK_COMMON_H
# define MINITALK_COMMON_H
#include <sys/types.h>

typedef struct s_bit_msg
{
    pid_t pid;
    int nb_bits;
    int current_ind;
    char buffer[4096];
    char c;
    time_t last_time;
} t_bit_msg;

int get_bit_at(char c, int pos);
void append_bit_to_display(pid_t pid, int bit);
int send_msg(pid_t pid, char* msg);
#endif