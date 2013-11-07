int my_power_it(int nb, int power)
{
	int result;

	if(power == 0)
	{
		return (1);
	}
	else if(power < 0)
	{
		return (0);
	}
	result = nb;
	while(power > 1)
	{
		result = result * nb;
		//Gestion de l'overflow
		if(result < 0)
		{
			return (0);
		}
		power = power - 1;
	}
	return (result);
}