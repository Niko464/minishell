/*
** EPITECH PROJECT, 2020
** double_redirect_left_two.c
** File description:
** This file handles a list of commands
*/

#include "my.h"
#include "mini_shell.h"
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>

int do_the_fork_redirect_left(main_info_t *infos, char *found_path,
    char **word_array, int pipe_fd[2])
{
    int to_return = 0;

    if (fork() == 0) {
        dup2(pipe_fd[0], 0);
        to_return = execve(found_path, word_array, infos->envp);
    }
    return (to_return);
}

void start_execution(main_info_t *infos, char *found_path,
    char **word_array, int pipe_fd[2])
{
    int status = 0;
    int exec_value = 84;

    exec_value = do_the_fork_redirect_left(infos, found_path,
        word_array, pipe_fd);
    if (exec_value == -1) {
        handle_execve_error(word_array[0]);
        return;
    }
    wait3(0, 0, NULL);
    handle_signals(status);
}

void execve_for_double_redirect_left(main_info_t *infos,
    char *found_path, char **word_array, char **input)
{
    struct stat s;
    int pipe_fd[2];
    pipe(pipe_fd);
    for (int i = 0; input[i] != 0; i++) {
        write(pipe_fd[1], input[i], my_strlen(input[i]));
        write(pipe_fd[1], "\n", 1);
    }
    close(pipe_fd[1]);
    if (check_if_file_is_dir(found_path) == 1)
        return;
    if (stat(found_path, &s) == 0 && (s.st_mode & S_IXUSR)) {
        start_execution(infos, found_path, word_array, pipe_fd);
    } else {
        my_perror(word_array[0]);
        my_perror(": Permissions denied.\n");
    }
}

void search_program_redirect_left(main_info_t *infos, char **word_array,
    char **input)
{
    char *found_path = search_path(infos, word_array);
    if (my_strcmp(found_path, "N/A") != 0) {
        execve_for_double_redirect_left(infos, found_path, word_array, input);
    } else {
        my_perror(word_array[0]);
        my_perror(": Command not found.\n");
    }
}

void handle_command_redirect_left(main_info_t *infos, char **word_array,
    char **input)
{
    if (word_array[0][0] != '/')
        search_program_redirect_left(infos, word_array, input);
    else
        execve_for_double_redirect_left(infos, word_array[0], word_array,
            input);
}