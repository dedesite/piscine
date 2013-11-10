#include <my.h>

void my_8r2()
{
	char y;
	char* chessboard;

	chessboard = my_strdup("XXXXXXXX");
	y = '0';
	while(y < '8')
	{
		check_reine(chessboard, 0, y, 0);
		y = y + 1;
	}
}