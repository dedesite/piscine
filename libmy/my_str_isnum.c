#include <my.h>

int my_str_isnum(char *str)
{
	while(*str && is_num(*str))
	{
		str = str + 1;
	}
	return (*str == '\0');
}