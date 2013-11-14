#include <my.h>

char* my_evil_str(char* str)
{
	char c;
	int i;
	int j;

	i = 0;
	j = my_strlen(str) - 1;
	while(i < j)
	{
		c = str[i];
		str[i] = str[j];
		str[j] = c;
		i = i + 1;
		j = j - 1;
	}
	return (str);
}