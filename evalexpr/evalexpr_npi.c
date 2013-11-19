#include <evalexpr.h>

/*
** http://crlf.be/
*/
char** expr_to_npi(char** expr_tab, char* base, char* operators)
{
    int i;
    char* current_token;

    i = 0;
    while(expr_tab[i])
    {
        current_token = expr_tab[i];
        if(is_operand(current_token, base))
        {
            add out
        }
        else if(is_parenthesis(current_token, operators, 1))
        {
            add pile
        }
        else if(is_operator(current_token, operators))
        {
            if(size(pile) == 0)
                add pile
            else if(is_parenthesis(first_pile, operators, 1))
                add pile
            else if(is_operator_prioritary(current_token, first_pile, operators))
                add_pile
            else
            {
                op = pop_pile
                add_out(op);
                add_pile(current_token);
            }
        }
        else
        {
            free(expr_tab[i]);
            token = pop_pile();
            while(!is_parenthesis(token, operators, 1))
            {
                add_out(token);
                token = pop_pile();
            }
            free(token);
        }
        i++;
    }
}
