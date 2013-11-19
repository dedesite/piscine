#include <stdlib.h>
#include <mylist.h>

void* my_list_pop(t_list** list)
{
    t_list* to_free;
    void* data;

    to_free = *list;
    data = (*list)->data;
    *list = (*list)->next;
    free(to_free);
    return(data);
}