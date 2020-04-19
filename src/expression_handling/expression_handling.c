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
    int save_stdout = dup(1);
    close(fileno(stdout));
    int output_file = open(command[2], O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (output_file < 0)
        return;
    dup2(output_file, 1);
    char **new_command = remove_arg_from_command(command, 1);
    new_command = remove_arg_from_command(new_command, 1);
    if (is_a_known_command(infos, new_command) == 0)
        handle_other_commands(infos, new_command);
    dup2(save_stdout, 1);
}