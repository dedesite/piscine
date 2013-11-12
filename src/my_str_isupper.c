#include <my.h>

int my_str_isupper(char *str)
{
	while(*str && is_upper(*str))
	{
		str = str + 1;
	}
	return (*str == '\0');
}