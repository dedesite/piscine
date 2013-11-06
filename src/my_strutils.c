int is_letter(char c)
{
	return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}

int is_lower(char c)
{
	return (c >= 'a' && c <= 'z');
}

int is_upper(char c)
{
	return (c >= 'A' && c <= 'Z');
}

int is_alphanum(char c)
{
	return (is_letter(c) || (c >= '0' && c <= '9'));
}

int is_printable(char c)
{
	return (c >= ' ' && c <= '~');
}