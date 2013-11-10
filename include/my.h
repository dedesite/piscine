#ifndef _MY_H_
# define _MY_H_

void my_putchar(char c);
void my_isneg(int nb);
void my_put_nbr(int nb);
void my_swap(int *a, int *b);
void my_putstr(char *str);
int my_strlen(char *str);
int my_getnbr(char *str);
void my_sort_int_tab(int *tab, int size);
int my_power_rec(int nb, int power);
int my_square_root(int nb);
int my_is_prime(int nombre);
int my_find_prime_sup(int nb);
char *my_strcpy(char *dest, char *src);
char *my_strncpy(char *dest, char *src, int nb);
char *my_revstr(char *str);
char *my_strstr(char *str, char *to_find);
int my_strcmp(char *s1, char *s2);
int my_strncmp(char *s1, char *s2, int nb);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcapitalize(char *str);
int my_str_isalpha(char *str);
int my_str_isnum(char *str);
int my_str_islower(char *str);
int my_str_isupper(char *str);
int my_str_isprintable(char *str);
void my_showstr(char *str);
void my_showmem(char *str, int size);
char *my_strcat(char *dest, char *src);
char *my_strncat(char *dest, char *src, int nb);
int my_strlcat(char *dest, char *src, int size);
char* my_strdup(char* str);
char *convert_base(char *nbr, char *base_from, char *base_to);
int is_lower(char c);
int is_upper(char c);
int is_num(char c);
int is_alpha(char c);
int is_alphanum(char c);
int is_printable(char c);
char **my_str_to_wordtab(char *str);
#endif