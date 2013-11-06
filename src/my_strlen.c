int my_strlen(char* str)
{
	int len;

	len = 0;
	while(str[len] != '\0')
	{
		len = len + 1;
	}
	return (len);
}