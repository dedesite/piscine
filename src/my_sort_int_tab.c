void my_sort_int_tab(int* tab, int size)
{
	int i;
	int j;
	int min;
	int temp;

	i = 0;
	j = 0;
	min = 0;
	while(i < size)
	{
		while(j < size)
		{
			if(tab[j] < tab[min])
			{
				min = j;
			}
			j = j + 1;
		}
		temp = tab[i];
		tab[i] = tab[min];
		tab[min] = temp;
		i = i + 1;
		j = i;
		min = i;
	}
}