#include "evalexpr.h"
#include "my.h"

char* get_expr(unsigned int size)
{
    (void)(size);
    return (0);
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
