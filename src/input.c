/*
** EPITECH PROJECT, 2020
** input.c
** File description:
** This is the file that handles user's input
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include "my.h"
#include "mini_shell.h"

int is_a_known_command(main_info_t *infos, char **word_array)
{
    if (my_strcmp(word_array[0], "exit") == 0) {
        handle_exit(infos, word_array);
        return (1);
    } else if (my_strcmp(word_array[0], "cd") == 0) {
        handle_cd(infos, word_array);
        return (1);
    }
    if (my_strcmp(word_array[0], "env") == 0) {
        handle_env(infos);
        return (1);
    } else if (my_strcmp(word_array[0], "setenv") == 0) {
        handle_setenv(infos, word_array);
        return (1);
    }
    if (my_strcmp(word_array[0], "unsetenv") == 0) {
        handle_unsetenv(infos, word_array);
        return (1);
    }
    return (0);
}

int ask_input(main_info_t *infos)
{
    char *buffer = malloc(sizeof(char) * 1);
    size_t bufsize = 1;

    my_putstr("> ");
    int eof = getline(&buffer, &bufsize, stdin);
    if (eof == -1)
        return (1);
    buffer[my_strlen(buffer) - 1] = '\0';
    if (my_strcmp(buffer, "") != 0 && my_strcmp(buffer, ";") != 0) {
        buffer = my_remove_spaces(buffer);
        handle_list_of_commands(infos, buffer);
    }
    return (0);
}