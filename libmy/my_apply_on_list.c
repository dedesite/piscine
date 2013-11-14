#include <mylist.h>

void my_apply_on_list(t_list *begin, void (*f)(void*))
{
	t_list* l;

	l = begin;
	while(l->next)
	{
		f(l->data);
		l = l->next;
	}
}