#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#include "my.h"

char* build_path(char* dirname, char* file)
{
    char* path;

    if(dirname)
    {
        path = malloc(my_strlen(dirname) + my_strlen(file) + 2);
        path = my_strcpy(path, dirname);
        path = my_strcat(path, "/");
        path = my_strcat(path, file);
    }
    else
        path = NULL;
    return (path);
}

void my_exec(char** env_path, char** cmd, char** env)
{
    int i;
    char* filename;
    int permission;
    pid_t pid;

    permission = -1;
    filename = my_strdup(cmd[0]);
    i = 0;
    while(filename)
    {
        if(access(filename, X_OK) == 0)
        {
            permission = 1;
            pid = fork();
            if(pid == 0)
                execve(filename, &cmd[1], env);
        }
        else if(errno == EACCES)
        {
            permission = 0;
        }
        free(filename);
        filename = build_path(env_path[i], cmd[0]);
        ++i;
    }
    if (permission == 0)
        my_putstr("Permission denied.\n");
    else if (permission == -1)
        my_putstr("Command not found.\n");
}

char* find_path(char** env)
{
    int i;
    char* path;

    path = 0;
    i = 0;
    while(env[i])
    {
        path = my_strstr(env[i], "PATH=");
        if(path != NULL && my_strcmp(&path[5], &env[i][5]) == 0)
            return (&path[5]);
        ++i;
    }
    return (path);
}

int main(int argc, char** argv, char** env)
{
    char buffer[4096];
    int len;
    char* path;
    char** splited_path;
    char** cmd;

    path = find_path(env);
    splited_path = 0;
    if(path)
        splited_path = split_str(path, ':');
    my_putstr("$>");
    while((len = read(0, buffer, 4096)) > 0)
    {
        cmd = my_str_to_wordtab(buffer);
        my_exec(splited_path, cmd, env);
        my_putstr("$>");
    }
    return (0);
}