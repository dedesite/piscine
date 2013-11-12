#include <my.h>

void display_numbers(char first_1, char first_2, char second_1, char second_2, int display_comma)
{
	if(display_comma)
	{
		my_putchar(',');
		my_putchar(' ');
	}
	my_putchar(first_1);
	my_putchar(first_2);
	my_putchar(' ');
	my_putchar(second_1);
	my_putchar(second_2);
}

void my_aff_comb2()
{
	char first_1 = '0';
	char first_2 = '0';
	char second_1 = '0';
	char second_2 = '1';

	display_numbers(first_1, first_2, second_1, second_2, 0);
	while(first_1 != '9' || first_2 != '8')
	{
		second_2 = second_2 + 1;
		if(second_2 > '9')
		{
			second_2 = '0';
			second_1 = second_1 + 1;
			if(second_1 > '9')
			{
				second_1 = '0';
				first_2 = first_2 + 1;
				if(first_2 > '9')
				{
					first_2 = '0';
					first_1 = first_1 + 1;
				}
				second_2 = first_2 + 1;
				second_1 = first_1;
			}
		}
		display_numbers(first_1, first_2, second_1, second_2, 1);
	}
}