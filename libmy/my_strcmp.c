int my_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while(s1[i] == s2[i] && s1[i] && s2[i])
	{
		i = i + 1;
	}
	if(s1[i] == '\0' && s2[i] == '\0')
	{
		return (0);
	}
	else
	{
		return (s1[i] - s2[i]);
	}
}

int find_in_tab(char** tab, int size, char* to_find)
{
	int i;

	i = 0;
	while(i < size)
	{
		if(my_strcmp(tab[i], to_find) == 0)
			return (i);
		i = i + 1;
	}
	return (-1);
}