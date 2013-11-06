int my_factorielle_it(int nb)
{
	int factorielle;
	int i;

	if(nb < 0 || nb > 12)
	{
		return (0);
	}
	factorielle = 1;
	i = 1;
	while(nb > 0)
	{
		factorielle = factorielle * i;
		if(factorielle < 0)
		{
			return (0);
		}
		nb = nb - 1;
		i = i + 1;
	}
	return (factorielle);
}