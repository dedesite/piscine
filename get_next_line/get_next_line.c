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

/*
char *get_next_line(const int fd)
{
    static char *buff = 0;
    static int len = 0;
    int i;
    char* str;

    if (!buff)
        buff = malloc(BUFFER_SIZE * sizeof(char));
    if (!*buff)
        len = read(fd, buff, BUFFER_SIZE);
    if (len == 0)
        return (0);
    i = 0;
    str = malloc(len + 1);
    while (i < len && buff[i] != '\n')
    {
        str[i] = buff[i];
        i++;
    }
    str[i] = 0;
    if (i >= len - 1)
    {
        //Prob : buff n'est pas forcément à BUFFER_SIZE
        printf("here");
        //buff = buff - BUFFER_SIZE - 1 + (i == len);
        //buff[0] = 0;
        if(i == len)
        {
            printf("ligne longue");
        }
    }
    else
    {
        printf("here");
        buff = &buff[i + 1];
        len = len - (i + 1);
        printf("len:%d\n",len );
    }
    return (str);
}
*/
/*
char *get_next_line(const int fd)
{
    static int prev_ind = 0;
    static int prev_len = 0;
    static char buff[BUFFER_SIZE];
    int len;
    int i;
    int j;
    char* str;

    if(prev_ind == 0)
    {
        len = read(fd, buff, BUFFER_SIZE);
        prev_len = len;
        printf("read:%d\n", len);
    }
    else
    {
        len = prev_len - prev_ind;
        //printf("keep:%d\n", len);
    }
    str = malloc(len + 1);
    if(str == NULL || len == 0)
        return (0);
    i = prev_ind;
    while(i < prev_ind + len && buff[i] != '\n')
        i++;
    len = i - prev_ind;
    //printf("new len:%d\n", len);
    
    i = 0;
    j = prev_ind;
    while(i < len)
    {
        //printf("buff=%s\n", &buff[j]);
        str[i] = buff[j];
        i++;
        j++;
    }
    str[i] = 0;
    printf("%s\n", str);
    if(j != prev_len)
        prev_ind = j + 1;
    else
        prev_ind = 0;
    return (str);
}*/

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