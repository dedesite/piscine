int my_factorielle_rec(int nb)
{
	if(nb > 0 && nb < 13)
	{
		if(nb > 1)
		{
			return my_factorielle_rec(nb - 1) * nb;		
		}
		else
		{
			return nb;
		}
	}
	else if(nb == 0)
	{
		return (1);
	}
	else
	{
		return (0);
	}
	
}