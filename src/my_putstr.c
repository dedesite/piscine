void my_putstr(char* str)
{
	write(1, str, my_strlen(str));
}