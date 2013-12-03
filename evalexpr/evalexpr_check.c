#include "my.h"
#include "evalexpr.h"

int str_uniq_char(char* s)
{
    int i;

    i = 0;
    while(s[i])
    {
        if(count_str_token(s, s[i]) != 1)
            return (0);
        i++;    
    }
    
    return (1);
}

int check_base(char* b)
{
    return (my_strlen(b) > 1 && str_uniq_char(b));
}

int check_ops(char* ops)
{
    return (my_strlen(ops) == 7 && str_uniq_char(ops));
}
