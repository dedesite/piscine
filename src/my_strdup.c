#include <stdlib.h>
#include <my.h>

char* my_strdup(char* str)
{
	int len;
	char* dup;

	len = my_strlen(str) + 1;
	dup = malloc(len);
	if(dup == NULL)
		return (NULL);
	dup = my_strcpy(dup, str);
	dup[len - 1] = '\0';
	return (dup);
}