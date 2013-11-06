void my_put_nbr(int nbr)
{
	my_putnbr_base(nbr, "0123456789");
	/*if(nbr < 0)
	{
		my_putchar('-');
	}
	else
	{
		nbr = -nbr;
	}
	if(nbr <= -10)
	{
		my_put_nbr(-(nbr / 10));	
	}
	my_putchar(-(nbr % 10) + 48);*/
}