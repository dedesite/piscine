#include <my.h>

int my_strlcat(char *dest, char *src, int size)
{

	int len;
	int src_len;
	int i;

	len = my_strlen(dest);
	src_len = my_strlen(src);
	if(len > size)
		return (size + src_len);
	i = 0;
	while(i + len < size - 1 && src[i])
	{
		dest[len + i] = src[i];
		i = i + 1;
	}
	dest[len + i] = '\0';
	return (len + src_len);
}