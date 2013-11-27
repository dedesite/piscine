#include <my.h>
#include <evalexpr.h>

int is_expr_valid(char* expr, char* base, char* operators)
{
    int i;

    i = 0;
    while (expr[i])
    {
        if (expr[i] != ' ' && my_strchr(base, expr[i]) == 0 
            && my_strchr(operators, expr[i]) == 0)
            return (0);
        i++;
    }
    return (1);
}

int is_operator(char* token, char* operators)
{
    if(my_strlen(token) != 1)
        return (0);
    return (my_strstr(&operators[2], token) != 0);
}

/**
** A valider l'odre des opérateurs prioritaire avec le sujet de la bistro
** Pour l'instant c'est ()/ *-+%
*/
int is_operator_prioritary(char* op_1, char* op_2, char* operators)
{
    int pos_1;
    int pos_2;

    pos_1 = get_char_pos(operators, *op_1);
    pos_2 = get_char_pos(operators, *op_2);
    if( pos_1 > 3 && pos_2 < 4)
        return (1);
    return (0);
}

int is_operand(char* token, char* base)
{
    int i;

    i = 0;
    while(token[i])
    {
        if(my_strchr(base, token[i]) == 0)
            return (0);
        i++;
    }
    return (1);
}

int is_parenthesis(char* token, char* operators, int open)
{
    if(my_strlen(token) != 1)
        return (0);
    if(open)
        return (token[0] == operators[0]);
    else
        return (token[0] == operators[1]);
}