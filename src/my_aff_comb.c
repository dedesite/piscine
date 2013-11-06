void display_numbers(char first, char second, char third, int display_comma)
{
	if(display_comma)
	{
		my_putchar(',');
		my_putchar(' ');
	}
	my_putchar(first);
	my_putchar(second);
	my_putchar(third);
}

void my_aff_comb()
{
	char first = '0';
	char second = '1';
	char third = '2';

	display_numbers(first, second, third, 0);
	while(first < '8')
	{
		third = third + 1;
		if(third > '9')
		{
			second = second + 1;
			third = second + 1;
			if(second > '9')
			{
				first = first + 1;
				second = first + 1;
				third = second + 1;
			}	
		}
		if(second <= '9' && third <= '9')
		{
			display_numbers(first, second, third, 1);	
		}		
	}
	my_putchar('\n');
}