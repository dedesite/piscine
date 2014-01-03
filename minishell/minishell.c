#include <sys/types.h>
#include <sys/wait.h>
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

int my_exec(char** env_path, char** cmd, char** env)
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
            pid = fork();
            if(pid == 0)
                execve(filename, cmd, env);
            else
                return (pid);
        }
        else if(errno == EACCES)
            permission = 0;
        free(filename);
        filename = build_path(env_path[i], cmd[0]);
        ++i;
    }
    return (permission);
}

char* find_path(char** env)
{
    int i;

    i = 0;
    while(env[i])
    {
        if(my_strncmp(env[i], "PATH=", 5) == 0)
            return (&env[i][5]);
        ++i;
    }
    return (0);
}

int main(int argc, char** argv, char** env)
{
    char buffer[4096];
    int len;
    char* path;
    char** splited_path;
    char** cmd;
    int permission;
    int status;

    path = find_path(env);
    splited_path = 0;
    if(path)
        splited_path = split_str(path, ':');
    my_putstr("$>");
    while((len = read(0, buffer, 4096)) > 0)
    {
        cmd = my_str_to_wordtab(buffer);
        permission = my_exec(splited_path, cmd, env);
        if (permission == 0)
            my_putstr("Permission denied.\n");
        else if (permission == -1)
            my_putstr("Command not found.\n");
        else
            waitpid(permission, &status, 0);
        my_putstr("$>");
    }
    return (0);
}