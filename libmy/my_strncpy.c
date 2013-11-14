char *my_strncpy(char *dest, char *src, int n)
{
	int i;

	i = 0;
	while(src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		i = i + 1;
	}
	if(i == n)
	{
		dest[i] = '\0';
	}
	return dest;
}