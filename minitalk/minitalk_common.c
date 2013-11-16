#include <my.h>
#include <stdio.h>
/** Return a char bit at a given position*/
int get_bit_at(char c, int pos)
{
    return ((c >> pos) & 1);
}

/**
** Append a bit to a buffered string which is display
** when a null char is detected
*/
void append_bit_to_display(int bit)
{
    static int nb_bits = 0;
    static int current_ind = 0;
    static char buffer[4096];
    static char c = 0;

    if(bit == 1)
        c = (c << 1) | 0x01;
    else
        c = (c << 1);
    nb_bits++;
    if(nb_bits >= 8)
    {
        buffer[current_ind] = c;
        nb_bits = 0;
        c = 0;
        if(buffer[current_ind] == '\0')
        {
            my_putstr(buffer);
            current_ind = 0;
        }
        current_ind++;
    }
}