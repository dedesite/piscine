int my_showstr(char *str)
{
	int i;

	i = 0;
	while(str[i])
	{
		if(is_printable(str[i]))
		{
			my_putchar(str[i]);
		}
		else
		{
			my_putchar('\\');
			if(str[i] < 16)
			{
				my_putchar('0');
			}
			my_putnbr_base(str[i], "0123456789abcdef");
		}
		i = i + 1;
	}
}