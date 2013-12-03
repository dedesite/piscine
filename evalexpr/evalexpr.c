#include <stdlib.h>
#include <my.h>
#include <evalexpr.h>

int is_operand_start(char* expr, char* base, int ind)
{
    return (my_strchr(base, expr[ind]) != 0 && 
        (ind == 0 || my_strchr(base, expr[ind - 1]) == 0));
}

int is_operand_end(char* expr, char* base, int ind)
{
    return (my_strchr(base, expr[ind]) == 0 &&
        (ind != 0 && my_strchr(base, expr[ind - 1]) != 0));
}

int count_expr_tokens(char* expr, char* base, char* operators)
{
    int i;
    int nb_tokens;

    nb_tokens = 0;
    i = 0;
    while(expr[i])
    {
        if(my_strchr(operators, expr[i]) != 0)
            nb_tokens++;
        if(is_operand_start(expr, base, i))
            nb_tokens++;

        i++;
    }
    return (nb_tokens);
}

void add_operator(char** tab, int* token_ind, char op, char* operators)
{
    int ind;
    (void)(operators);

    ind = *token_ind;
    /*if(ind != 0 && is_operator(tab[ind - 1], operators))
    {
        if(operators[OP_PLUS_IDX] != op &&
            operators[OP_SUB_IDX] != op)
            return (0);
        if(operators[OP_PLUS_IDX] == tab[ind - 1][0] ||
            operators[OP_SUB_IDX] == tab[ind - 1][0])
    }*/
    tab[ind] = malloc(2);
    tab[ind][0] = op;
    tab[ind][1] = '\0';
    (*token_ind)++;    
}

char** expr_to_tab(char* expr, char* base, char* operators)
{
    char** tab;
    int nb_tokens;
    int i;
    int token_ind;
    int start_op;

    if (!is_expr_valid(expr, base, operators))
        return (0);
    nb_tokens = count_expr_tokens(expr, base, operators) + 1;
    tab = malloc(nb_tokens * sizeof(char*));
    i = 0;
    token_ind = 0;
    start_op = 0;
    while(expr[i])
    {
        if(is_operand_start(expr, base, i))
            start_op = i;
        if(is_operand_end(expr, base, i))
        {
            tab[token_ind] = malloc(i - start_op + 1);
            my_strncpy(tab[token_ind], &expr[start_op], i - start_op);
            token_ind++;
        }
        if(my_strchr(operators, expr[i]) != 0)
            add_operator(tab, &token_ind, expr[i], operators);
        i++;
    }
    tab[token_ind] = 0;
    return (tab);
}

int eval_expr(char* str)
{
    char** tab;

    tab = expr_to_tab(str, "0123456789", "()/*-+%");
    if(tab == 0)
        return (0);

    return (0);
}