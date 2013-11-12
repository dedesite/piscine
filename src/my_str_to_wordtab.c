#include <stdlib.h>
#include <my.h>

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
		if(is_word_start(str, i))
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