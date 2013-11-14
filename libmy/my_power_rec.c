int my_power_rec(int nb, int power)
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
	else if(power > 1)
	{
		result = my_power_rec(nb, power - 1) * nb;
		if(result < 0)
		{
			return (0);
		}
		else
		{
			return (result);
		}
	}
	else
	{
		return nb;
	}
}