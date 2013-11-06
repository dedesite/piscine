int is_inbase(char c, char* base)
{
	int i;

	i = 0;
	while(base[i] && base[i] != c)
	{
		i = i + 1;
	}
	return (base[i] != '\0');
}

int getnbr_len(char *str, char *base, int start)
{
	int len;

	len = 0;
	while(is_inbase(str[start], base))
	{
		len = len + 1;
		start = start + 1;
	}
	return (len);
}

int get_base_ind(char c, char* base)
{
	int i;

	i = 0;
	while(base[i])
	{
		if(base[i] == c)
		{
			return (i);
		}
		i = i + 1;
	}
	return (-1);
}

int my_getnbr_base(char *str, char *base)
{
	int i;
	int nb_moins;
	int len_nb;
	int final_nb;
	int power;
	int base_len;

	i = 0;
	nb_moins = 0;
	len_nb = 0;
	final_nb = 0;
	power = 1;
	base_len = my_strlen(base);
	//check le nombre de "-" avant le nombre pour déterminer son signe
	while(str[i] == '+' || str[i] == '-')
	{
		if(str[i] == '-')
		{
			nb_moins = nb_moins + 1;
		}
		i = i + 1;
	}
	//Calcul de la taille du nombre
	len_nb = getnbr_len(str, base, i);
	i = i + (len_nb - 1);
	//On travail en négatif pour gérer l'overflow
	while(len_nb > 0)
	{
		final_nb = final_nb - get_base_ind(str[i], base) * power;
		if(final_nb > 0)
		{
			return (0);
		}
		power = power * base_len;
		len_nb = len_nb - 1;
		i = i - 1;
	}
	if(nb_moins % 2 == 0)
	{
		final_nb = -final_nb;
		if(final_nb < 0)
		{
			return (0);
		}
	}
	return final_nb;
}