#include <stdlib.h>
#include <mylist.h>

t_list* add_in_list(void* data, t_list* list)
{
	t_list* l;

	l = malloc(sizeof(t_list));
	l->data = data;
	l->next = list;
	return l;
}

t_list *my_params_in_list(int ac, char **av)
{
	t_list* l;
	int i;

	i = 0;
	l = 0;
	while(i < ac)
	{
		l = add_in_list(av[i], l);
		i = i + 1;
	}
	return (l);
}