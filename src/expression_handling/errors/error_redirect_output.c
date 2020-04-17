/*
** EPITECH PROJECT, 2020
** error_redirect_output.c
** File description:
** This file handles a list of commands
*/

#include "my.h"
#include "mini_shell.h"

int check_errors_redirect_output(char **command, int nbr_args,
    int expr_position)
{
    if (nbr_args > 3) {
        my_putstr("Ambiguous output redirect.\n");
        return (1);
    } else if (expr_position == 0 && nbr_args == 1) {
        my_putstr("Missing name for redirect.\n");
        return (1);
    }
    if (expr_position == 0 && nbr_args > 1) {
        my_putstr("Invalid null command.\n");
        return (1);
    } else if (expr_position == 1 && nbr_args < 3) {
        my_putstr("Missing name for redirect.\n");
        return (1);
    }
    return (0);
}