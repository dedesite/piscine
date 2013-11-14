#include <mylist.h>

void my_rev_list(t_list **begin)
{
	t_list* l;
	t_list* temp;
	t_list*	temp_next;

	l = *begin;
	temp = 0;
	while(l->next)
	{
		temp_next = l->next;
		l->next = temp;
		temp = l;
		l = temp_next;
	}
	l->next = temp;
	*begin = l;
}