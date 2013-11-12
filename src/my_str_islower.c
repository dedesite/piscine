#include <my.h>

int my_str_islower(char *str)
{
	while(*str && is_lower(*str))
	{
		str = str + 1;
	}
	return (*str == '\0');
}