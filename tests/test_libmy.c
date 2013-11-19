#include <string.h>
#include <stdlib.h>
#include <my.h>
#include <mylist.h>
#include <test.h>

void test_my_put_nbr()
{
	my_put_nbr(-10);
	my_putchar('\n');
	my_put_nbr(42);
	my_putchar('\n');
	my_put_nbr(-42);
	my_putchar('\n');
	my_put_nbr(0);
	my_putchar('\n');
	my_put_nbr(2147483647);
	my_putchar('\n');
	my_put_nbr(-2147483648);
	my_putchar('\n');	
}


void test_my_aff_comb()
{
	//my_aff_comb();
}

void test_my_aff_combn()
{
	/*test(add_one_at_pos(2567, 2) == 2600);
	test(add_one_at_pos(2567, 0) == 2568);
	test(add_one_at_pos(2567, 1) == 2570);
	test(add_one_at_pos(2567, 3) == 3000);
	test(add_one_at_pos(7, 0) == 8);
	test(add_one_at_pos(77, 0) == 78);
	test(add_one_at_pos(0, 3) == 1000);

	my_aff_combn(2);*/
}

void test_my_putstr()
{
	char str[10];
	
	str[0] = 'a';
	str[1] = 'l';
	str[2] = 'l';
	str[3] = 'o';
	str[4] = '\0';
	my_putstr(str);
	my_putchar('\n');
	my_putstr("yop");
	my_putchar('\n');
}

void test_mystrlen()
{
	char str[10];
	
	str[0] = 'a';
	str[1] = 'l';
	str[2] = 'l';
	str[3] = 'o';
	str[4] = '\0';
	test(my_strlen(str) == 4);
	test(my_strlen("yop") == 3);
}

void test_my_evil_str()
{
	char* str1 = strdup("abcdef");
	char* str2 = strdup("abcdefg");
	char* str3 = strdup("kayak");
	
	test(my_strcmp("fedcba", my_evil_str(str1)) == 0);
	test(my_strcmp("gfedcba", my_evil_str(str2)) == 0);
	test(my_strcmp("kayak", my_evil_str(str3)) == 0);
}

void test_getnbr()
{
	test(my_getnbr("+---+--++---+---+---+-42") == -42);
	test(my_getnbr("+---+--++---+---+---+42") == 42);
	test(my_getnbr("42a43") == 42);
	test(my_getnbr("11000000000000000000000042") == 0);
	test(my_getnbr("-11000000000000000000000042") == 0);
	test(my_getnbr("-2147483648") == -2147483648);
	test(my_getnbr("2147483647") == 2147483647);
	test(my_getnbr("2147483648") == 0);
}

void test_my_sort_int_tab()
{
	int tab[5] = {5, 8, 1, 7, 9};
	my_sort_int_tab(tab, 5);
	test(tab[0] == 1 && tab[1] == 5 && tab[2] == 7 && tab[3] == 8 && tab[4] == 9);
}

void test_my_factorielle_it()
{
	test(my_factorielle_it(0) == 1);
	test(my_factorielle_it(-1) == 0);
	test(my_factorielle_it(3) == 6);
	test(my_factorielle_it(12) == 479001600);
	test(my_factorielle_it(13) == 0);
}

void test_my_factorielle_rec()
{
	test(my_factorielle_rec(0) == 1);
	test(my_factorielle_rec(-1) == 0);
	test(my_factorielle_rec(3) == 6);
	test(my_factorielle_rec(12) == 479001600);
	test(my_factorielle_rec(13) == 0);
}

void test_my_power_it()
{
	test(my_power_it(1, 2) == 1);
	test(my_power_it(2, 0) == 1);
	test(my_power_it(2, 1) == 2);
	test(my_power_it(3, 3) == 27);
	test(my_power_it(2, 2) == 4);
	test(my_power_it(2, -2) == 0);
	test(my_power_it(9, 10) == 0);
	test(my_power_it(-9, 2) == 81);
}

void test_my_power_rec()
{
	test(my_power_rec(1, 2) == 1);
	test(my_power_rec(2, 0) == 1);
	test(my_power_rec(2, 1) == 2);
	test(my_power_rec(3, 3) == 27);
	test(my_power_rec(2, 2) == 4);
	test(my_power_rec(2, -2) == 0);
	test(my_power_rec(9, 10) == 0);
	test(my_power_rec(-9, 2) == 81);
}

void test_strcpy()
{
	char str[5];
	test_str(my_strcpy(str, "test"), "test");
	test_str(my_strcpy(str, "tes"), "tes");
}

void test_strncpy()
{
	char str[5];
	test(my_strcmp(strncpy(str, "test", 2), "te") == 0);
	test(my_strcmp(my_strncpy(str, "test", 2), "te") == 0);
	
	test(my_strcmp(my_strncpy(str, "test", 7), "test") == 0);
	//my_putstr(str);
}

void test_revstr()
{
	char str[6] = "testa";
	test(my_strcmp(my_revstr(str), "atset") == 0);
}

void test_strstr()
{
	test(my_strcmp(my_strstr("coucou les lapinous", "les"), "les lapinous") == 0);
	test(my_strstr("test ou les lapins", "rac") == NULL);
	test(my_strcmp(my_strstr("les bananes c'est bon", "bo"), "bon") == 0);
}

void test_my_strcmp()
{
	char str[3] = "ab";
	test(my_strcmp("ab", "aa") == 1);
	test(my_strcmp("ac", "aa") == 1);
	test(my_strcmp("aa", "ab") == -1);
	test(my_strcmp("aa", "a") == 1);
	test(my_strcmp("aa", "abcdef") == -1);
	test(my_strcmp("ab", "ab") == 0);
	test(my_strcmp("ab", str) == 0);
	test(my_strncmp("abcd", "ab", 2) == 0);
	test(my_strncmp("aacd", "ab", 2) == -1);
	test(my_strncmp("abcd", "ab", 8) == 1);
}

void test_strupcase()
{
	test(my_strcmp(my_strupcase(strdup("salUt cA va ?")), "SALUT CA VA ?") == 0);
}

void test_strlowcase()
{
	test(my_strcmp(my_strlowcase(strdup("salUt cA va ?")), "salut ca va ?") == 0);
}

void test_strcapitalize()
{
	char* str;
	str = strdup("salut, comMent ca va ? 42mots quaRante-deUx; cinQuante+et+un");
	str = my_strcapitalize(str);
	test_str(str, "Salut, Comment Ca Va ? 42mots Quarante-Deux; Cinquante+Et+Un");
}

void test_utils()
{
	test(is_lower('b') == 1);
	test(is_lower('B') == 0);
	test(is_upper('B') == 1);
	test(is_upper('b') == 0);
	test(is_alpha('B') == 1);
	test(is_alpha('b') == 1);
	test(is_alpha('[') == 0);
	test(is_alpha('@') == 0);

	test(is_alpha('{') == 0);
	test(is_alpha(' ') == 0);
	test(is_alpha('2') == 0);
	test(is_lower('2') == 0);
	test(is_upper('2') == 0);
	test(is_printable('2') == 1);
	test(is_printable('\n') == 0);
	test(is_alphanum('9') == 1);
	test(is_alphanum('{') == 0);
}

void test_str_is()
{
	test(my_str_isalpha("aioulkjJHGgjhk") == 1);
	test(my_str_isalpha("aioulkj32") == 0);
	test(my_str_isprintable("aioulkj32") == 1);
	test(my_str_isprintable("a\nioulkj32") == 0);
}

void test_putnbr_base()
{
	putlineb("Devrait afficher : 101010 ");
	my_putnbr_base(42, "01");
	putlineb("Devrait afficher : BABABA ");
	my_putnbr_base(42, "AB");
	putlineb("Devrait afficher : 2A ");
	my_putnbr_base(42, "0123456789ABCDEF");
	putlineb("Devrait afficher : -C ");
	my_putnbr_base(-12, "0123456789ABCDEF");
	putlineb("Devrait afficher : -4C8 ");
	my_putnbr_base(-1224, "0123456789ABCDEF");
}

void test_getnbr_base()
{
	test(my_getnbr_base("-42", "0123456789") == -42);
	test(my_getnbr_base("-101010", "01") == -42);
	test(my_getnbr_base("-BABABA", "AB") == -42);
	test(my_getnbr_base("-4C8", "0123456789ABCDEF") == -1224);
	test(my_getnbr_base("--4C8abc", "0123456789ABCDEF") == 1224);
}

void test_showstr()
{
	putlineb("Devrait afficher : coucou \\0a\\07\\0d ca va ? ");
	my_showstr("coucou \n\a\r ca va ?");
}

void test_showmem()
{
	my_showmem("Salut les aminches c'est cool show mem on fait de truc terrible", 5);
}

void test_mathutils()
{
	test(get_nb_at_pos(2547, 2) == 5);
	test(get_nb_at_pos(3, 2) == 0);
	test(get_nb_at_pos(3, -2) == 0);

	test(get_nb_len(0) == 1);
	test(get_nb_len(2) == 1);
	test(get_nb_len(-520) == 3);
	test(get_nb_len(520) == 3);
	test(get_nb_len(52123) == 5);
}

int get_group_num(int nb, int pos);
int get_to_sub(int last_sub);
int treat_group(int group, int* rest, int* to_sub);
void test_square_root()
{
	test(get_group_num(529, 0) == 29);
	test(get_group_num(529, 1) == 5);
	test(get_group_num(529, 2) == 0);
	test(get_group_num(529, -2) == 0);
	int rest = 0;
	int to_sub = 1;
	test(treat_group(5, &rest, &to_sub) == 2);
	test(rest == 1);
	my_put_nbr(to_sub);
	test(to_sub == 3);
	to_sub = 41;
	test(treat_group(29, &rest, &to_sub) == 3);
	test(rest == 0);
	test(get_to_sub(3) == 41);
	test(my_square_root(81) == 9);
	test(my_square_root(529) == 23);
	test(my_square_root(82) == 0);
}

void test_is_prime()
{
	test(my_is_prime(1) == 0);
	test(my_is_prime(2) == 1);
	test(my_is_prime(3) == 1);
	test(my_is_prime(5) == 1);
	test(my_is_prime(6) == 0);
	test(my_is_prime(7) == 1);
	test(my_is_prime(9) == 0);
}

void test_find_prime_sup()
{
	test(my_find_prime_sup(2) == 2);
	test(my_find_prime_sup(3) == 3);
	test(my_find_prime_sup(4) == 5);
	test(my_find_prime_sup(9) == 11);
}

int is_safe(char* chessboard, int x, char y);
void test_8r1()
{
	test(is_safe("02XXXXXX", 2, '5') == 1);
	test(is_safe("7777070X", 7, '0') == 0);
	test(is_safe("02XXXXXX", 2, '3') == 0);
	test(is_safe("02XXXXXX", 2, '1') == 0);
	test(is_safe("02XXXXXX", 2, '2') == 0);
	test(is_safe("025XXXXX", 2, '7') == 0);
	test(is_safe("05XXXXXX", 2, '2') == 0);
	test(is_safe("25XXXXXX", 2, '0') == 0);
	test(is_safe("25X6XXXX", 2, '7') == 0);
	test(is_safe("50X3XXXX", 2, '2') == 0);
	my_8r1();
	test(my_8r1() == 92);
	my_8r2();
	//my_put_nbr(my_8r1());
}

void test_strdup()
{
	char *s = my_strdup("coucou");
	test(my_strlen(s) == 6);
	my_putstr("Should print coucou : ");
	putline(s);
}

void test_strcat()
{
	char* dest;
	char* after;
	dest = malloc(10);
	dest = my_strcpy(dest, "coucou");
	after = my_strcat(dest, "gnu");
	test_str(dest, "coucougnu");
	test(dest == after);
	dest = my_strcpy(dest, "coucou");
	after = my_strncat(dest, "gnu", 2);
	test_str(dest, "coucougn");
	test(dest == after);
	dest = my_strcpy(dest, "coucou");
	after = my_strncat(dest, "gnu", 4);
	test_str(dest, "coucougnu");
	free(dest);
}

void test_strlcat()
{
	test(my_strlcat("Boobies", "a", 2) == 3);
	char* buff = malloc(10);
	buff = my_strcpy(buff, "coucou");
	test(my_strlcat(buff, "gnu", 10) == 9);
	buff = my_strcpy(buff, "coucou");
	test(my_strlcat(buff, "gnug", 6) == 10);
	buff = my_strcpy(buff, "coucou");
	test(my_strlcat(buff, "gnugnu", 10) == 12);
	buff = my_strcpy(buff, "coucou");
	test(my_strlcat(buff, "gnug", 5) == 9);
	free(buff);

}

void test_convert_base()
{
	char *s;
	s = convert_base("101010", "01", "0123456789ABCDEF");
	test_str(s, "2A");
	free(s);
	s = convert_base("BABABA", "AB", "ABCDEFGHIJKLMNOP");
	test_str(s, "CK");
	free(s);
}

void test_tab(char* str, char **tab)
{
	test_str(tab[0], "coucou");
	test_str(tab[1], "les");
	test_str(tab[2], "lapinous");
	test(tab[3] == 0);
	free(tab);
	free(str);
}

void test_count_str_token()
{
	test(count_str_token("coucou", 'c') == 2);
	test(count_str_token("salut|toi|ca|va", '|') == 3);
	test(count_str_token("salut|toi|ca|va", 'z') == 0);
}

void test_split_str()
{
	char* str = my_strdup("coucou les lapinous");
	char** tab = split_str(str, ' ');
	test_tab(str, tab);
	str = my_strdup("coucou|les|lapinous");
	tab = split_str(str, '|');
	test_tab(str, tab);
	str = my_strdup("|coucou||les|lapinous");
	tab = split_str(str, '|');
	test(tab[0][0] == 0);
	test_str(tab[1], "coucou");
	test(tab[2][0] == 0);
	test_str(tab[3], "les");
	free(str);
	free(tab);
}

void test_str_to_wordtab()
{
	test(count_str_words("coucou les lapinous") == 3);
	test(count_str_words("   coucou les    lapinous  ") == 3);
	test(count_str_words("coucou|les/lapinous  ") == 3);
	char* str = my_strdup("coucou les lapinous");
	char** tab = my_str_to_wordtab(str);
	test_tab(str, tab);
	str = my_strdup("   coucou les    lapinous  ");
	tab = my_str_to_wordtab(str);
	test_tab(str, tab);
	str = my_strdup("coucou|les/lapinous  ");
	tab = my_str_to_wordtab(str);
	test_tab(str, tab);
}

void test_big_endian()
{
	//Difficile à tester sur une machine big endian...
	test(is_big_endian()); 
}

void test_find_in_tab()
{
	char* tab[3] = {"coucou", "les", "lapinous"};
	test(find_in_tab(tab, 3, "coucou") == 0);
	test(find_in_tab(tab, 3, "les") == 1);
	test(find_in_tab(tab, 3, "lapinous") == 2);
	test(find_in_tab(tab, 3, "lapinou") == -1);
}

void test_sort_word_tab()
{
	char* tab[4] = {"coucou", "les", "lapinous", 0};
	my_sort_wordtab(tab);
	test_str(tab[0], "coucou");
	test_str(tab[1], "lapinous");
	test_str(tab[2], "les");
}

void test_advanced_sort_word_tab()
{
	char* tab[4] = {"coucou", "les", "lapinous", 0};
	my_advanced_sort_wordtab(tab, my_strcmp);
	test_str(tab[0], "coucou");
	test_str(tab[1], "lapinous");
	test_str(tab[2], "les");
}

void test_put_ptr()
{
	int i;

	i = 0;
	test_put("pointer adresse in Hexa");
	my_putptr_base(&i, "0123456789ABCDEF");
	test_put("pointer adresse in base 10");
	my_put_ptr(&i);
	putline("");
}

void test_my_list_add()
{
	t_list* l;

	l = my_list_add("coucou", 0);
	test_str(l->data, "coucou");
	test(l->next == 0);
	l = my_list_add("lapinou", l);
	test_str(l->data, "lapinou");
	test_str(l->next->data, "coucou");	
}

void test_my_list_pop()
{
	t_list* l;
	t_list* first;

	first = my_list_add("coucou", 0);
	l = my_list_add("lapinou", first);
	char* s = my_list_pop(&l);
	test_str(s, "lapinou");
	test(l == first);
}

void test_params_in_list()
{
	t_list* l;
	char* tab[2] = {"coucou", "lapinou"};

	l = my_params_in_list(2, tab);
	test_str(l->data, "lapinou");
}

void test_my_list_size()
{	
	t_list* l;
	char* tab[2] = {"coucou", "lapinou"};

	l = my_params_in_list(2, tab);
	test(my_list_size(l) == 2);
}

void test_rev_list()
{
	t_list* l;
	char* tab[4] = {"coucou", "les", "lapinous", "africains"};
	l = my_params_in_list(4, tab);
	my_rev_list(&l);
	test_str(l->data, "coucou");
	test_str(l->next->data, "les");
}

void rev_str_list(void* s)
{
	my_revstr(s);
}

void test_apply_on_list()
{
	t_list* l;
	char* tab[4] = {my_strdup("coucou"), my_strdup("les"), my_strdup("lapinous"), my_strdup("africains")};
	l = my_params_in_list(4, tab);
	my_apply_on_list(l, rev_str_list);
	test_str(l->data, "sniacirfa");
}

void test_get_char_pos()
{
	test(get_char_pos("coucou", 'c') == 0);
	test(get_char_pos("coucou", 'o') == 1);
	test(get_char_pos("coucou", 'u') == 2);
	test(get_char_pos("coucou", 'z') == -1);
}

int main()
{
	test_my_list_pop();
	return (0);
}
