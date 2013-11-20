#include <stdlib.h>
#include <evalexpr.h>
#include <mylist.h>
#include <my.h>
/*
** http://crlf.be/
*/
char** expr_to_npi(char** expr_tab, char* base, char* operators)
{
    int i;
    int out_ind;
    char* current_token;
    char* token;
    t_list* stack;

    i = 0;
    out_ind = 0;
    stack = 0;
    while(expr_tab[i])
    {
        current_token = expr_tab[i];
        if(is_operand(current_token, base))
        {
            expr_tab[out_ind] = current_token;
            out_ind++;
        }
        else if(is_parenthesis(current_token, operators, 1))
        {
            stack = my_list_add(current_token, stack);
        }
        else if(is_operator(current_token, operators))
        {
            if(my_list_size(stack) == 0)
                stack = my_list_add(current_token, stack);
            else if(is_parenthesis(stack->data, operators, 1))
                stack = my_list_add(current_token, stack);
            else if(is_operator_prioritary(current_token, stack->data, operators))
                stack = my_list_add(current_token, stack);
            else
            {
                token = my_list_pop(&stack);
                expr_tab[out_ind] = token;
                out_ind++;
                stack = my_list_add(current_token, stack);
            }
        }
        else
        {
            free(expr_tab[i]);
            token = my_list_pop(&stack);
            while(!is_parenthesis(token, operators, 1))
            {
                expr_tab[out_ind] = token;
                token = my_list_pop(&stack);
                out_ind++;
            }
            free(token);
        }
        i++;
    }
    expr_tab[out_ind] = 0;
    return (expr_tab);
}
