int is_lower(char c)
{
	return (c >= 'a' && c <= 'z');
}

int is_upper(char c)
{
	return (c >= 'A' && c <= 'Z');
}

int is_num(char c)
{
	return (c >= '0' && c <= '9');
}

int is_alpha(char c)
{
	return (is_lower(c) || is_upper(c));
}

int is_alphanum(char c)
{
	return (is_alpha(c) || is_num(c));
}

int is_printable(char c)
{
	return (c >= ' ' && c <= '~');
}

int is_word_start(char* str, int i)
{
	return (is_alphanum(str[i]) && (i == 0 || !is_alphanum(str[i -1])));
}

int is_word_end(char* str, int i)
{
	return (!is_alphanum(str[i]) && (i != 0 && is_alphanum(str[i - 1])));
}

int count_str_words(char* str)
{
	int i;
	int nb_words;

	i = 0;
	nb_words = 0;
	while (str[i])
	{
		if(is_word_start(str, i))
			nb_words = nb_words + 1;
		i = i + 1;
	}
	return nb_words;
}

int get_char_pos(char* s, char c)
{
	int i;

	i = 0;
	while(s[i])
	{
		if(s[i] == c)
			return i;
		i++;
	}
	return (-1);
}