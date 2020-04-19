/*
** EPITECH PROJECT, 2020
** error_redirect_output_append.c
** File description:
** This file handles a list of commands
*/

#include "my.h"
#include "mini_shell.h"

int check_errors_redirect_output_append(char **command, int nbr_args,
    int expr_position)
{
    if (expr_position == 0 && nbr_args == 1) {
        my_putstr("Missing name for redirect.\n");
        return (1);
    }
    if (expr_position == 0 && nbr_args > 1) {
        my_putstr("Invalid null command.\n");
        return (1);
    } else if (expr_position >= nbr_args - 1) {
        my_putstr("Missing name for redirect.\n");
        return (1);
    }
    return (0);
}