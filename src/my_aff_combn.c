int add_one_at_pos(nb, pos)
{
	int power;
	int temp_pos;
	int temp_nb;

	power = 1;
	temp_pos = pos;
	while(temp_pos > 0)
	{
		power = power * 10;
		temp_pos = temp_pos - 1;
	}
	nb = nb + power;
	temp_pos = 0;
	temp_nb = nb;
	power = 1;
	while(temp_pos < pos)
	{
		nb = nb - (temp_nb % 10) * power;
		power = power * 10;
		temp_nb = temp_nb / 10;
		temp_pos = temp_pos + 1;
	}
	return (nb);
}


void my_aff_combn(int n)
{
	int i;
	int to_add;
	int end;
	char c;
	int temp = 0;

	i = 0;
	to_add = 0;
	end = 0;
	c = '0';
	while(end == 0)
	{
		while(i < n)
		{
			c = c + get_nb_at_pos(to_add, (n - 1) - i);
			my_putchar(c);
			if(c >= '9')
			{
				if(i == 0)
				{
					end = 1;
				}
			}
			to_add = add_one_at_pos(to_add, (n - 1) - i);
			i = i + 1;
		}
		i = 0;
		c = '0';
		temp++;
		/*if(temp >= 10)
			end = 1;*/
		if(!end)
		{
			my_putchar(',');
			my_putchar(' ');	
		}
	}
	my_putchar('\n');
}