#include <my.h>

void my_sort_wordtab(char **tab)
{
    my_advanced_sort_wordtab(tab, my_strcmp);
}