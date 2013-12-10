#include <stdlib.h>
#include <unistd.h>

#include "get_next_line.h"

char* my_realloc(char* ptr, size_t size)
{
    char* temp;
    int i;

    temp = ptr;
    ptr = malloc(size);
    i = 0;
    while(temp[i])
    {
        ptr[i] = temp[i];
        i++;
    }
    free(temp);
    return (ptr);
}

char get_char(const int fd)
{
    static char buff[BUFFER_SIZE];
    static char* ptr_buff;
    static int len = 0;
    char c;

    if(len == 0)
    {
        len = read(fd, buff, BUFFER_SIZE);
        ptr_buff = (char*)&buff;
        if(len == 0)
            return (0);
    }
    c = *ptr_buff;
    ptr_buff++;
    len--;
    return c;
}

char *get_next_line(const int fd)
{
    char c;
    char* str;
    int len;

    len = 0;
    str = malloc(BUFFER_SIZE + 1);
    if (str == NULL)
        return (0);
    c = get_char(fd);
    while(c != '\n' && c != '\0')
    {
        str[len] = c;
        c = get_char(fd);
        len++;
        if(len % (BUFFER_SIZE+1) == 0)
            str = my_realloc(str, len + BUFFER_SIZE + 1);
    }
    str[len] = 0;
    if(c == 0 && str[0] == 0)
        return (0);
    return (str);
}