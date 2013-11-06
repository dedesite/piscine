void my_putnbr_base_rec(int nbr, char* base, int base_len)
{
	if(nbr < 0)
	{
		my_putchar('-');
	}
	else
	{
		nbr = -nbr;
	}
	if(nbr <= -base_len)
	{
		my_putnbr_base_rec(-(nbr / base_len), base, base_len);	
	}
	my_putchar(base[-(nbr % base_len)]);
}

void my_putnbr_base(int nbr, char *base)
{
	int len;

	len = my_strlen(base);
	my_putnbr_base_rec(nbr, base, len);
}