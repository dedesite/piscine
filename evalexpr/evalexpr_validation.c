#include <my.h>
#include <evalexpr.h>

int is_expr_valid(char* expr, char* base, char* operators)
{
    int i;
    char prec;
    int nb_open_parentethis;
    int nb_close_parentethis;

    i = 0;
    nb_open_parentethis = 0;
    nb_close_parentethis = 0;
    prec = expr[i];
    while (expr[i])
    {
        if(my_strchr(base, expr[i]) != 0)
            prec = expr[i];
        else if(my_strchr(operators, expr[i]) != 0)
        {
            if(is_parenthesis(expr[i], operators, 0))
                nb_close_parentethis++;
            else if(is_parenthesis(expr[i], operators, 1))
                nb_open_parentethis++;
            else if(i != 0 && is_operator(prec, operators))
            {
                if(my_strchr(&operators[4], prec) || 
                    my_strchr(&operators[4], expr[i]))
                    return (0);
            }
            prec = expr[i];
        }
        else if (expr[i] != ' ')
            return (0);
        i++;
    }
    return (nb_open_parentethis == nb_close_parentethis);
}

int is_operator(char token, char* operators)
{
    return (my_strchr(&operators[2], token) != 0);
}

/**
** A valider l'odre des opérateurs prioritaire avec le sujet de la bistro
** Pour l'instant c'est ()/ *-+%
*/
int is_operator_prioritary(char op_1, char op_2, char* operators)
{
    int pos_1;
    int pos_2;

    pos_1 = get_char_pos(operators, op_1);
    pos_2 = get_char_pos(operators, op_2);
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

int is_parenthesis(char token, char* operators, int open)
{
    if(open)
        return (token == operators[OP_OPEN_PARENT_IDX]);
    else
        return (token == operators[OP_CLOSE_PARENT_IDX]);
}