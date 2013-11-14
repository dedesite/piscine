int get_nb_at_pos(int nb, int pos)
{
	int i;

	i = 0;
	while(i < pos)
	{
		nb = nb / 10;
		i = i + 1;
	}
	if(pos >= 0)
	{
		return nb % 10;	
	}
	else
	{
		return 0;
	}
}

int get_nb_len(int nb)
{
	if(nb < 0)
	{
		nb = -nb;
	}
	if(nb >= 10)
	{
		return (get_nb_len(nb / 10) + 1);
	}
	else
	{
		return (1);
	}
}