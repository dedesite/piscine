#include <my.h>

int my_str_isprintable(char *str)
{
	while(*str && is_printable(*str))
	{
		str = str + 1;
	}
	return (*str == '\0');
}