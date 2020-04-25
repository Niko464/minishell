/*
** EPITECH PROJECT, 2020
** expression_handling.c
** File description:
** This file handles a list of commands
*/

#include "my.h"
#include "mini_shell.h"
#include <stdlib.h>
#include <stdio.h>

char **get_pipe_first_cmd(char **command, int nbr_args, int expr_position)
{
    char **first_command = command;
    for (int i = 0; i < (nbr_args - expr_position); i++)
        first_command = remove_arg_from_command(first_command, expr_position);
    return first_command;
}

char **get_pipe_second_cmd(char **command, int expr_position)
{
    char **sec_command = command;
    for (int i = 0; i <= expr_position; i++)
        sec_command = remove_arg_from_command(sec_command, 0);
    return sec_command;
}

void handle_pipe_redirect(main_info_t *infos, char **cmd,
    int expr_position)
{
    int nbr_args = 0;
    int pipe_fd[2];
    for (int i = 0; cmd[i] != 0; i++)
        nbr_args++;
    if (check_errors_pipe(nbr_args, expr_position) != 0)
        return;
    char  **first_cmd = get_pipe_first_cmd(cmd, nbr_args, expr_position);
    char  **sec_cmd = get_pipe_second_cmd(cmd, expr_position);
    pipe(pipe_fd);
    int save_stdout = dup(1);
    close(1);
    dup2(pipe_fd[1], 1);
    handle_other_commands(infos, first_cmd);
    dup2(save_stdout, 1);
    int save_stdin = dup(0);
    close(pipe_fd[1]);
    close(0);
    dup2(pipe_fd[0], 0);
    handle_other_commands(infos, sec_cmd);
    dup2(save_stdin, 0);
}