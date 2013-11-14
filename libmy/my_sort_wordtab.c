#include <my.h>

void my_sort_wordtab(char **tab)
{
    int i;
    int j;
    int min;
    char* temp;

    i = 0;
    j = i;
    min = i;
    while(tab[i])
    {
        while(tab[j])
        {
            if(my_strcmp(tab[j], tab[min]) < 0)
            {
                min = j;
            }
            j = j + 1;
        }
        temp = tab[i];
        tab[i] = tab[min];
        tab[min] = temp;
        i = i + 1;
        j = i;
        min = i;
    }
}