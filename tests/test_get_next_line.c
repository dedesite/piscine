#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#include "test.h"
#include "get_next_line.h"
#include "my.h"


void test_petites_lignes()
{
    char* s;
    int fd;

    fd = open("../tests/assets/test_petites_lignes.txt", O_RDONLY);

    s = get_next_line(fd);
    //putline(s);
    test_str(s, "coucou");
    s = get_next_line(fd);
    //putline(s);
    test_str(s, "ca");
    s = get_next_line(fd);
    test_str(s, "va?");

    close(fd);
}

void test_grandes_lignes()
{
    char* s;
    int fd;

    fd = open("../tests/assets/test_grandes_lignes.txt", O_RDONLY);

    s = get_next_line(fd);
    test(my_strlen(s) > BUFFER_SIZE);
    s = get_next_line(fd);
    test_str(s, "yop");

    close(fd);
}

void test_lignes_vide()
{
    int fd;
    int i = 0;
    char* s;

    fd = open("../tests/assets/test_lignes_vide.txt", O_RDONLY);
    while(i < 4)
    {
        s = get_next_line(fd);
        test_str(s, "");
        i++;      
    }
    s = get_next_line(fd);
    test_str(s, "salut");
    close(fd);
}

void test_meme_lignes()
{
    int fd;
    int i = 0;
    char* s;

    fd = open("../tests/assets/test_meme_lignes.txt", O_RDONLY);
    while((s = get_next_line(fd)))
    {
        test_str(s, "salut");
        free(s);
        i++;
    }
    test(i == 19);
    close(fd);    
}

char get_char(const int fd);
void test_get_char()
{
    int i = 0;
    char c;
    int fd;

    fd = open("../tests/assets/test_get_char.txt", O_RDONLY);
    while(i < 69)
    {
        c = get_char(fd);
        i++;
    }
    test(c == 'o');
    close(fd);
}

int main(int ac, char** av)
{
    test_petites_lignes();
    test_grandes_lignes();
    test_lignes_vide();
    test_meme_lignes();
    test_get_char();
    return (0);
}