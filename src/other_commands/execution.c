/*
** EPITECH PROJECT, 2020
** exit.c
** File description:
** This is the file that handles the exit command
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <signal.h>
#include <errno.h>
#include "my.h"
#include "mini_shell.h"

void handle_execve_error(char *cmd_name)
{
    if (errno == ENOEXEC) {
        my_perror(cmd_name);
        my_perror(": Exec format error. Wrong Architecture.\n");
        kill(getpid(), SIGKILL);
        free(cmd_name);
        return;
    }
}

int check_if_file_is_dir(char *path)
{
    DIR *dir = opendir(path);
    if (dir != NULL) {
        my_perror(path);
        my_perror(": Permission denied.\n");
        closedir(dir);
        return (1);
    }
    return (0);
}