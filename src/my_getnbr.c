int my_getnbr(char* str)
{
	int i;
	int nb_moins;
	int len_nb;
	int final_nb;
	int power;

	i = 0;
	nb_moins = 0;
	len_nb = 0;
	final_nb = 0;
	power = 1;
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
	while(str[i] >= '0' && str[i] <= '9')
	{
		len_nb = len_nb + 1;
		i = i + 1;
	}
	i = i - 1;
	//On travail en négatif pour gérer l'overflow
	while(len_nb > 0)
	{
		final_nb = final_nb - (str[i] - 48) * power;
		if(final_nb > 0)
		{
			return (0);
		}
		power = power * 10;
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