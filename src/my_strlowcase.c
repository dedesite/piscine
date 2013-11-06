char *my_strlowcase(char *str)
{
	int i;

	i = 0;
	while(str[i] != '\0')
	{
		if(str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] = str[i] + 32 ;
		}
		i = i + 1;
	}
	return str;
}