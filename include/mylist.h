#ifndef MYLIST_H_
# define MYLIST_H_

typedef struct s_list
{
    void *data;
    struct s_list *next;
} t_list;

#endif