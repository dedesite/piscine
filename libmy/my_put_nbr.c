#include <my.h>

void my_put_nbr(int nbr)
{
	my_putnbr_base(nbr, "0123456789");
}

void my_put_ptr(void* ptr)
{
  my_putptr_base(ptr, "0123456789"); 
}