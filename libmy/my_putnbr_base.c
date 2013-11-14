#include <my.h>

void my_convertnbr_base_rec(int nbr, char* base, int base_len, char* str)
{
	if(nbr < 0)
	{
		my_putchar('-');
	}
	else
	{
		nbr = -nbr;
	}
	if(nbr <= -base_len)
	{
		my_convertnbr_base_rec(-(nbr / base_len), base, base_len, str + 1);	
	}
	else
	{
		str[1] = '\0';
	}
	*str = base[-(nbr % base_len)];
}

void my_putnbr_base(int nbr, char *base)
{
	int len;
	char str[33];

	len = my_strlen(base);
	my_convertnbr_base_rec(nbr, base, len, str);
	my_revstr(str);
	my_putstr(str);
}

void my_putptr_base(void* ptr, char* base)
{
	int* tab;
	int nb_put;
	int i;

	tab = (int*)ptr;
	nb_put = sizeof(void*) / sizeof(int);
	i = 0;
	while(i < nb_put)
	{
		my_putnbr_base(tab[i], base);
		i = i + 1;
	}
}