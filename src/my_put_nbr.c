void my_put_nbr(int nbr)
{
	if(nbr < 0)
	{
		my_putchar('-');
	}
	else
	{
		nbr = -nbr;
	}
	if(nbr < -10)
	{
		my_put_nbr(-(nbr / 10));	
	}
	my_putchar(-(nbr % 10) + 48);
}