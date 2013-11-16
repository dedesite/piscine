#include <unistd.h>
#include <test.h>
#include <minitalk_common.h>
#include <my.h>

void test_get_bit_at()
{
    char c = 42;

    test(get_bit_at(c, 0) == 0);
    test(get_bit_at(c, 1) == 1);
    test(get_bit_at(c, 2) == 0);
    test(get_bit_at(c, 3) == 1);
    test(get_bit_at(c, 4) == 0);
    test(get_bit_at(c, 5) == 1);
    test(get_bit_at(c, 6) == 0);
    test(get_bit_at(c, 7) == 0);
}

void test_append_bit_to_display()
{
    char* s = "coucou";
    int s_ind;
    int i;
    int bit;

    test_put("42:coucou84:coucou");
    s_ind = 0;
    while ((s[s_ind] && s_ind == 0) || s[s_ind - 1])
    {
        i = 7;
        while (i >= 0)
        {
            bit = get_bit_at(s[s_ind], i);
            append_bit_to_display(42, bit);
            append_bit_to_display(84, bit);
            i--;
        }
        s_ind++;
    }
    putline("");
}

void test_check_errors()
{
    char* s = "coucou";
    int s_ind;
    int i;
    int bit;

    test_put("scramble something");
    s_ind = 0;
    while ((s[s_ind] && s_ind == 0) || s[s_ind - 1])
    {
        i = 7;
        while (i >= 0)
        {
            bit = get_bit_at(s[s_ind], i);
            append_bit_to_display(42, bit);
            i--;
            //Don't push the last bit
            if(s_ind == 6 && i == 1)
                i--;
        }
        s_ind++;
    }
    sleep(2);
    append_bit_to_display(42, 1);
}

int main()
{
    test_append_bit_to_display();
    test_append_bit_to_display();
    test_check_errors();
    return (0);
}