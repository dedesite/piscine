#include <string.h>

void test(result)
{
	if(result)
		my_putchar('Y');
	else
		my_putchar('N');
	my_putchar('\n');
}

void test_str(char* s1, char* s2)
{
	test(my_strcmp(s1, s2) == 0);
}

/*
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
*/

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

	test(get_at_pos(2547, 2) == 5);
	test(get_at_pos(3, 2) == 0);

	my_aff_combn(2);*/
}

void test_my_putstr()
{
	/*char str[10];
	
	str[0] = 'a';
	str[1] = 'l';
	str[2] = 'l';
	str[3] = 'o';
	str[4] = '\0';
	my_putstr(str);
	my_putchar('\n');
	my_putstr("yop");
	my_putchar('\n');*/
}

void test_mystrlen()
{
	/*
	char str[10];
	
	str[0] = 'a';
	str[1] = 'l';
	str[2] = 'l';
	str[3] = 'o';
	str[4] = '\0';
	test(my_strlen(str) == 4);
	test(my_strlen("yop") == 3);
	*/
}

char* my_evil_str(char*);
void test_my_evil_str()
{
	/*
	char* str1 = strdup("abcdef");
	char* str2 = strdup("abcdefg");
	char* str3 = strdup("kayak");
	
	test(strcmp("fedcba", my_evil_str(str1)) == 0);
	test(strcmp("gfedcba", my_evil_str(str2)) == 0);
	test(strcmp("kayak", my_evil_str(str3)) == 0);
	*/
}

/*void test_getnbr()
{
	test(my_getnbr("+---+--++---+---+---+-42") == -42);
	test(my_getnbr("+---+--++---+---+---+42") == 42);
	test(my_getnbr("42a43") == 42);
	test(my_getnbr("11000000000000000000000042") == 0);
	test(my_getnbr("-11000000000000000000000042") == 0);
	test(my_getnbr("-2147483648") == -2147483648);
	test(my_getnbr("2147483647") == 2147483647);
	test(my_getnbr("2147483648") == 0);
}*/

void test_my_sort_int_tab()
{
	/*int tab[5] = {5, 8, 1, 7, 9};
	my_sort_int_tab(tab, 5);
	test(tab[0] == 1 && tab[1] == 5 && tab[2] == 7 && tab[3] == 8 && tab[4] == 9);*/
}
/*
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
*/
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
char *my_strcpy(char *dest, char *src);
char *my_strncpy(char *dest, char *src, int n);
char* my_revstr(char*);
/*void test_strcpy()
{
	char str[5];
	test(strcmp(my_strcpy(str, "test"), "test") == 0);
}

void test_strncpy()
{
	char str[5];
	test(strcmp(strncpy(str, "test", 2), "te") == 0);
	test(strcmp(my_strncpy(str, "test", 2), "te") == 0);
	
	test(strcmp(my_strncpy(str, "test", 7), "test") == 0);
	//my_putstr(str);
}

void test_revstr()
{
	char str[6] = "testa";
	test(strcmp(my_revstr(str), "atset") == 0);
}

char *my_strstr(char *str, char *to_find);
void test_strstr()
{
	test(strcmp(my_strstr("coucou les lapinous", "les"), "les lapinous") == 0);
	test(my_strstr("test ou les lapins", "rac") == NULL);
	test(strcmp(my_strstr("les bananes c'est bon", "bo"), "bon") == 0);
}*/
/*
void test_strcmp()
{
	char str[3] = "ab";
	test(strcmp("ab", "aa") == 1);
	test(strcmp("ac", "aa") == 1);
	test(strcmp("aa", "ab") == -1);
	test(strcmp("aa", "a") == 1);
	test(strcmp("aa", "abcdef") == -1);
	test(strcmp("ab", "ab") == 0);
	test(strcmp("ab", str) == 0);
	test(my_strncmp("abcd", "ab", 2) == 0);
	test(my_strncmp("aacd", "ab", 2) == -1);
	test(my_strncmp("abcd", "ab", 8) == 1);
}
*/
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
/*void test_strupcase()
{
	test(strcmp(my_strupcase(strdup("salUt cA va ?")), "SALUT CA VA ?") == 0);
}*/

/*void test_strlowcase()
{
	test(strcmp(my_strlowcase(strdup("salUt cA va ?")), "salut ca va ?") == 0);
}*/

char *my_strcapitalize(char *str);
/*
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
*/
/*
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
*/
/*
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
*/

/*void test_showmem()
{
	my_showmem("Salut les aminches c'est cool show mem on fait de truc terrible", 5);
}*/
int main()
{
	test_my_power_it();
	return (0);
}