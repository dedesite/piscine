#include <stdlib.h>

#include "my.h"
#include "evalexpr.h"
#include "test.h"

void free_tab(char** tab)
{
    int i = 0;
    while(tab[i])
    {
        free(tab[i]);
        i++;
    }
    free(tab);
}

void test_is_expr_valid()
{
    test(is_expr_valid("   56 * ((6+2)   /   ( 8-7)* 2%3)", "0123456789", "()+-*/%"));
    test(is_expr_valid("   56 * ((6+2)   /   ( 8-7)* 2^3)", "0123456789", "()+-*/%") == 0);
    //Two operators *
    test(is_expr_valid("   56 * * ((6+2)   /   ( 8-7)* 2%3)", "0123456789", "()+-*/%") == 0);
    test(is_expr_valid("   56 * ((6--++2)   /   ( 8-7)* 2%3)", "0123456789", "()+-*/%"));
    //Too much parenthesis
    test(is_expr_valid("   56 * (((6+2)   /   ( 8-7)* 2%3)", "0123456789", "()+-*/%") == 0);
}

void test_expr_to_tab()
{
    char** tab;

    tab = expr_to_tab("   56 * ((6+2)   /   ( 8-7)* 2%3)", "0123456789", "()+-*/%");
    test_str(tab[0], "56");
    test_str(tab[1], "*");
    test_str(tab[2], "(");
    test_str(tab[3], "(");
    test_str(tab[4], "6");
    test_str(tab[8], "/");
    test_str(tab[16], "%");
    test(tab[19] == 0);
    free_tab(tab);
    tab = expr_to_tab("0101|[1001$10101]", "01", "[]+-*|$");
    test_str(tab[0], "0101");
    free_tab(tab);
    //wrong operator
    tab = expr_to_tab("   56 * ((6+2)   /   ( 8-7)* 2^3)", "0123456789", "()+-*/%");
    test(tab == 0);
    //wrong operande
    tab = expr_to_tab("   56 * ((6+2)   /   ( E-7)* 2^3)", "0123456789", "()+-*/%");
    test(tab == 0);
    //Wrong syntax
    tab = expr_to_tab("   56 * * ((6+2)   /   ( E-7)* 2^3)", "0123456789", "()+-*/%");
    test(tab == 0);
    //good syntax
    
    tab = expr_to_tab("   56 * ((6++-2)   /   ( 8-7)* 2%3)", "0123456789", "()+-*/%");
    test(tab != 0);
    test_str(tab[5], "-");
    free_tab(tab);
}

void test_is_operator()
{
    test(is_operator('*', "()+-*/%"));
    test(is_operator('$', "()+-*/%") == 0);
    test(is_operator('$', "()+-*/$"));
}

void test_is_operator_prioritary()
{
    test(is_operator_prioritary('*', '-', "()+-*/%"));
    test(is_operator_prioritary('-', '*', "()+-*/%") == 0);
    test(is_operator_prioritary('.', ';', "()+.;/%") == 0);
}

void test_is_operand()
{
    test(is_operand("56", "0123456789"));
    test(is_operand("BD", "0123456789") == 0);
    test(is_operand("BD", "0123456789ABCDEF"));

}

void test_is_parenthesis()
{
    test(is_parenthesis('(', "()+-*/%", 1));
    test(is_parenthesis(')', "()+-*/%", 1) == 0);
    test(is_parenthesis('[', "[]/*-+%", 1));
    test(is_parenthesis(')', "()+-*/%", 0));
    test(is_parenthesis('(', "()+-*/%", 0) == 0);
}

void test_count_expr_words()
{
    int nb = count_expr_tokens("   56 * ((6+2)   /   ( 8-7)* 2%3)", "01234567890", "()+-*/%");
    test(nb == 19);
}

void test_expr_to_npi()
{
    char** tab;

    tab = expr_to_tab("56 * ((6+2)   /   ( 8-7)* 2%3)", "0123456789", "()+-*/%");
    tab = expr_to_npi(tab, "0123456789", "()+-*/%");
    test_str(tab[0], "56");
    test_str(tab[1], "6");
    test_str(tab[2], "2");
    test_str(tab[3], "+");
    test_str(tab[4], "8");
    test_str(tab[5], "7");
    free_tab(tab);
}

void test_eval_expr()
{
    test(eval_expr("5+3") == 8);
    test(eval_expr("   56 * ((6+4)   /   ( 8-3)* 3%2)") == 112);
}

void test_check_base()
{
    //TODO : Tester qu'il n'y a pas 2 fois le même caractère dans la base
    test(check_base("0") == 0);
    test(check_base("01"));
    test(check_base("11") == 0);
    test(check_base("ABCDEFGA") == 0);
}

void test_check_operators()
{
    //TODO : tester la taille de la chaine des opérateurs
    test(check_ops("()+-*/%"));
    test(check_ops("()+-*/%^") == 0);
    test(check_ops("((+-*/%") == 0);
    test(check_ops("(+-*/%") == 0);

}

void test_str_uniq_char()
{
    test(str_uniq_char("01"));
    test(str_uniq_char("11") == 0);
    test(str_uniq_char("ABCDEFGA") == 0);
    test(str_uniq_char("salut"));
}

int main()
{
    test_is_expr_valid();
    /*test_is_operator();
    test_is_operator_prioritary();
    test_is_operand();
    test_is_parenthesis();
    test_count_expr_words();
    test_expr_to_tab();
    
    test_expr_to_npi();
    test_check_base();
    test_check_operators();
    test_str_uniq_char();*/
    //test_eval_expr();
    
    //TODO : Tester aussi la possibilité d'avoir des espace dans la base ou dans les opérateurs
    //TODO : Tester qu'il n'y a pas des caractère de la base dans les opérateurs
    return (0);
}