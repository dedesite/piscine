#include <my.h>

char *my_strncat(char *dest, char *src, int nb)
{
	int len;
	int i;

	len = my_strlen(dest);
	i = 0;
	while(i < nb && src[i])
	{
		dest[len + i] = src[i];
		i = i + 1;
	}
	dest[len + i] = '\0';
	return (dest);
}