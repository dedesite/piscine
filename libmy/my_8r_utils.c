#include <my.h>

int is_safe(char* chessboard, int x, char y)
{
	int inc_i;
	int inc_j;
	int i;
	char j;
	int nb_check;
	
	if(my_strchr(chessboard, y))
		return (0);
	if(chessboard[x] != 'X')
		return (0);
	inc_i = -1;
	inc_j = -1;
	nb_check = 0;
	while(nb_check < 4)
	{
		i = x + inc_i;
		j = y + inc_j;
		while((i >= 0 && i < 8) && (j >= '0' && j < '8'))
		{
			if(chessboard[i] == j)
				return (0);
			i = i + inc_i;
			j = j + inc_j;
		}
		if(nb_check % 2 == 0)
			inc_i = -inc_i;
		inc_j = -inc_j;
		nb_check = nb_check + 1;
	}
	return (1);
}

int check_reine(char* chessboard, int x, char y, int* solutions)
{
	int one_time;

	if(is_safe(chessboard, x, y) == 1)
	{
		chessboard[x] = y;
		if(x >= 7)
		{
			if(solutions)
				*solutions = *solutions + 1;
			else
				putline(chessboard);
			chessboard[x] = 'X';
			return (1);
		}
		one_time = 0;
		y = '0';
		while(y < '8')
		{
			if(check_reine(chessboard, x + 1, y, solutions))
				one_time = 1;
			y = y + 1;
		}
		chessboard[x] = 'X';
		if (one_time)
			return (1);
		else
			return (0);
	}
	else
		return (0);
}