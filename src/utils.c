/*
** EPITECH PROJECT, 2020
** utils.c
** File description:
** This file handles a list of commands
*/

#include "my.h"
#include "mini_shell.h"
#include <stdio.h>

char **remove_arg_from_command(char **command, int index_to_rem)
{
    int nbr_args = 0;
    char **to_return = NULL;
    int index = 0;

    for (int i = 0; command[i] != 0; i++, nbr_args++);
    to_return = malloc(sizeof(char *) * nbr_args);
    for (int i = 0; i < nbr_args; i++) {
        if (i == index_to_rem)
            continue;
        int len = my_strlen(command[i]);
        to_return[index] = malloc(sizeof(char) * (len + 1));
        my_strcpy(to_return[index], command[i]);
        to_return[index][len] = '\0';
        index++;
    }
    to_return[nbr_args - 1] = 0;
    return to_return;
}