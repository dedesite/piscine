#include <stdlib.h>
#include <my.h>

int count_str_token(char* str, char token)
{
    int i;
    int nb_token;

    i = 0;
    nb_token = 0;
    while(str[i])
    {
        if(str[i] == token)
            nb_token++;
        i++;
    }
    return (nb_token);
}

char** split_str(char* str, char token)
{
    char** tab;
    int tab_len;
    int i;
    int current_word;

    tab_len = count_str_token(str, token) + 2;
    tab = malloc(tab_len * sizeof(char*));
    i = 0;
    current_word = 0;
    while(str[i])
    {
        if(i == 0 || str[i - 1] == '\0')
        {
            tab[current_word] = &str[i];
            current_word++;
        }
        if(str[i] == token)
            str[i] = '\0';
        i++;
    }
    tab[current_word] = 0;
    return (tab);
}