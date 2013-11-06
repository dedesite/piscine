char *my_strcapitalize(char *str)
{
	int i;

	i = 0;
	while(str[i] != '\0')
	{
		if(is_alpha(str[i]))
		{
			if(is_lower(str[i]) && (i == 0 || (i != 0 && !is_alphanum(str[i - 1]))))
			{
				str[i] = str[i] - 32 ;
			}
			else if(is_upper(str[i]))
			{
				str[i] = str[i] + 32 ;	
			}
		}
		i = i + 1;
	}
	return (str);
}