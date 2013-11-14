#include <mylist.h>

int my_list_size(t_list *begin)
{
	int size;
	t_list* l;

	l = begin;
	size = 0;
	while(l->next)
	{
		size = size + 1;
		l = l->next;
	}
	size = size + 1;
	return (size);
}