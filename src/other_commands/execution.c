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

void execute_program(main_info_t *infos, char *found_path, char **word_array)
{
    int exec_value = 0;
    exec_value = execve(found_path, word_array, infos->envp);
    if (exec_value == ENOEXEC) {
        my_perror("Shit");
    }
}