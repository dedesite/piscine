#include <stdlib.h>
#include <my.h>

char **my_str_to_wordtab(char *str)
{
	char** tab;
	int nb_words;
	int current_word;
	int i;
	int start;

	str = my_strdup(str);
	nb_words = count_str_words(str);
	tab = malloc(sizeof(char*) * (nb_words + 1));
	i = 0;
	current_word = 0;
	while (str[i])
	{
		if(is_word_start(str, i))
			start = i;
		if(is_word_end(str, i))
		{
			str[i] = '\0';
			tab[current_word++] = my_strdup(&str[start]);
		}
		i = i + 1;
	}
	if(current_word != nb_words)
		tab[current_word++] = my_strdup(&str[start]);
	tab[current_word] = 0;
	free(str);
	return (tab);
}

char **str_to_wordtab(char* str, char* tokens)
{
	char** tab;
	int nb_words;
	int current_word;
	int i;
	int start;

	str = my_strdup(str);
	nb_words = count_str_words_token(str, tokens);
	tab = malloc((nb_words + 1) * sizeof(*tab));
	i = 0;
	current_word = 0;
	while (str[i])
	{
		if(str[i] =='-')
			putline("ok");
		if(is_word_start_token(str, i, tokens))
		{
			putline("start");
			start = i;
		}
		if(is_word_end_token(str, i, tokens))
		{
			str[i] = '\0';
			tab[current_word++] = my_strdup(&str[start]);
		}
		++i;
	}
	if(current_word != nb_words)
	{
		putline(&str[start]);
		tab[current_word++] = my_strdup(&str[start]);
	}
	tab[current_word] = 0;
	free(str);
	return (tab);
}