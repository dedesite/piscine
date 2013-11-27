#include "evalexpr.h"
#include "my.h"

int check_base(char* b)
{

}

int check_ops(char* ops)
{

}

char* get_expr(unsigned int size)
{

}

int main(int ac, char **av)
{
    if (ac > 1)
    {
        my_put_nbr(eval_expr(av[1]));
        my_putchar('\n');     
    }
    return (0);
}
