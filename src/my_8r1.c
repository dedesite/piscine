int is_safe(char** chessboard, int x, int y)
{
	int nb_check;
	int i;
	int j;
	int inc_i;
	int inc_j;

	inc_i = -1;
	inc_j = -1;
	nb_check = 0;
	while(nb_check < 8)
	{
		i = x + inc_i;
		j = y + inc_j;
		while(i >= 0 && i < 8 && j >= 0 && j < 8)
		{
			if(chessboard[i][j] == 'D')
				return (0);
			i = i + 1
		}
		inc_j = inc_j + 1;
		if(nb_check % 3 == 0)
		{
			inc_i = inc_i + 1;
			inc_j = -1;
		}
		if(inc_j == 0 && inc_i == 0)
		{
			inc_j = inc_j + 1;
		}
		i = x + inc_i;
		j = y + inc_j;		
		nb_check = nb_check + 1;
	}
	return (1);
}


int my_8r1()
{
	int i;
	int j;
	char chessboard[8][8];

	i = 0;
	while(i < 8)
	{
		j = 0;
		while(j < 8)
		{
			chessboard[i][j] = 'O';
			j = j + 1
		}
		i = i + 1;
	}

}