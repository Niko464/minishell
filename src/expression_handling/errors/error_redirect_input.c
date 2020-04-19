/*
** EPITECH PROJECT, 2020
** error_redirect_input.c
** File description:
** This file handles a list of commands
*/

#include "my.h"
#include "mini_shell.h"

int check_errors_redirect_input(char **command, int nbr_args,
    int expr_position)
{
    if (nbr_args > 2) {
        int input_file = open(command[expr_position + 1], O_RDONLY);
        if (input_file < 0) {
            my_perror(command[expr_position + 1]);
            my_perror(": No such file or directory\n");
            return (1);
        }
    }
    if (expr_position == 0 && nbr_args == 1) {
        my_perror("Missing name for redirect.\n");
        return (1);
    }
    if (expr_position == 0 && nbr_args > 1) {
        my_perror("Invalid null command.\n");
        return (1);
    } else if (expr_position >= nbr_args - 1) {
        my_perror("Missing name for redirect.\n");
        return (1);
    }
    return (0);
}