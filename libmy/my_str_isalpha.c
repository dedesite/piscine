#include <my.h>

int my_str_isalpha(char *str)
{
	while(*str && is_alpha(*str))
	{
		str = str + 1;
	}
	return (*str == '\0');
}