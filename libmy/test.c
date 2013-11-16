#include <my.h>
#include <mylist.h>

void test(int result)
{
    if(result)
        my_putchar('.');
    else
        my_putchar('N');
}

void test_str(char* s1, char* s2)
{
    test(my_strcmp(s1, s2) == 0);
}

void test_put(char* s)
{
    putlineb("Should display \"");
    my_putstr(s);
    my_putstr("\" : ");
}