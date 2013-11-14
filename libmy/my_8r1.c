#include <my.h>

int my_8r1()
{
	char y;
	char* chessboard;
	int solutions;

	chessboard = my_strdup("XXXXXXXX");
	solutions = 0;
	y = '0';
	while(y < '8')
	{
		check_reine(chessboard, 0, y, &solutions);
		y = y + 1;
	}
	return (solutions);
}