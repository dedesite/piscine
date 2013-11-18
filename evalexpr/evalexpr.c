#include <stdlib.h>
#include <my.h>

int count_expr_words(char* expr, char* base, char* operators)
{
    int i;
    int nb_words;

    nb_words = 0;
    i = 0;
    while(expr[i])
    {
        if(my_strchr(operators, expr[i]) != 0)
            nb_words++;
        if(my_strchr(base, expr[i]) != 0 && 
            (i == 0 || my_strchr(base, expr[i - 1]) == 0))
            nb_words++;

        i++;
    }
    return (nb_words);
}

char** expr_to_tab(char* expr, char* base, char* operators)
{
    char** tab;
    int nb_words;
    int i;
    int word_ind;

    if (!is_expr_valid(expr, base, operators))
        return (0);
    nb_words = count_expr_words(expr, base, operators);
    tab = malloc(nb_words * sizeof(char*));
    i = 0;
    word_ind = 0;
    while(expr[i])
    {
        if(my_strchr(operators, expr[i]) != 0)
        {
            tab[word_ind] = malloc(2);
            tab[word_ind][0] = expr[i];
            tab[word_ind][1] = '\0';
            word_ind++;
        }
        i++;
    }
    return (tab);
}

int eval_expr(char* str)
{
    return (0);
}