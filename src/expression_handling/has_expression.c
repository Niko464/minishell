/*
** EPITECH PROJECT, 2020
** has_expression.c
** File description:
** This file handles a list of commands
*/

#include "my.h"
#include "mini_shell.h"

int does_command_contain_expression(main_info_t *infos, char **command)
{
    for (int i = 0; command[i] != 0; i++) {
        if (my_strcmp(command[i], ">") == 0) {
            handle_redirect_output(infos, command, i);
            return (1);
        }
    }
    return (0);
}