#include <stdlib.h>
#include <my.h>

int is_word_begining(char* str, int i)
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
		if(is_word_begining(str, i))
			nb_words = nb_words + 1;
		i = i + 1;
	}
	return nb_words;
}

char **my_str_to_wordtab(char *str)
{
	char** tab;
	int nb_words;
	int current_word;
	int i;

	nb_words = count_str_words(str);
	tab = malloc(sizeof(char*) * (nb_words + 1));
	i = 0;
	current_word = 0;
	while (str[i])
	{
		if(is_word_begining(str, i))
		{
			tab[current_word] = &str[i];
			current_word = current_word + 1;
		}
		if(is_word_end(str, i))
			str[i] = '\0';
		i = i + 1;
	}
	tab[current_word] = 0;
	return (tab);
}