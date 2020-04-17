/*
** EPITECH PROJECT, 2020
** expression_handling.c
** File description:
** This file handles a list of commands
*/

#include "my.h"
#include "mini_shell.h"
#include <stdio.h>

void handle_redirect_output(main_info_t *infos, char **command,
    int expr_position)
{
    int nbr_args = 0;
    for (int i = 0; command[i] != 0; i++)
        nbr_args++;
    if (check_errors_redirect_output(command, nbr_args, expr_position) != 0) {
        return;
    }
    int output_file = open(command[2], O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (output_file < 0)
        return;
    int saved_stdout = dup(1);
    dup2(output_file, 1);
    my_putstr("TEST");
    dup2(saved_stdout, output_file);
    my_putstr("SEC TEST");
    close(output_file);
}