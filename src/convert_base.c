#include <stdlib.h>
#include <my.h>

char *convert_base(char *nbr, char *base_from, char *base_to)
{
	int convert_nb;
	int len;
	char *str;

	convert_nb = my_getnbr_base(nbr, base_from);
	len = my_strlen(base_to);
	str = malloc(33);
	my_convertnbr_base_rec(convert_nb, base_to, len, str);
	my_revstr(str);
	return str;
}