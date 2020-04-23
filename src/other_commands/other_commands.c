/*
** EPITECH PROJECT, 2020
** exit.c
** File description:
** This is the file that handles the exit command
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <signal.h>
#include "my.h"
#include "mini_shell.h"

char *search_path(main_info_t *infos, char **word_array)
{
    struct stat s;
    char *current_test = "\0";
    current_test = concat_slash(".", word_array[0]);
    if (lstat(current_test, &s) == 0)
        return (current_test);
    for (int i = 0; infos->paths[i] != 0; i++) {
        current_test = concat_slash(infos->paths[i], word_array[0]);
        if (lstat(current_test, &s) == 0)
            return (current_test);
    }
    return ("N/A\0");
}

void handle_signals(int status)
{
    if (status == SIGKILL)
        return;
    if (WIFSIGNALED(status)) {
        my_putstr(strsignal(WTERMSIG(status)));
        if (SIGFPE == status)
            write(2, "Floating exception", 18);
        if (SIGABRT == status)
            write(2, "Abort", 5);
        if (SIGILL == status)
            write(2, "Illegal instruction", 19);
        if (SIGSYS == status)
            write(2, "Bad System Call", 15);
        if (SIGTRAP == status)
            write(2, "Trace/Breakpoint Trap", 21);
        if (WCOREDUMP(status))
            write(2, " (core dumped)", 14);
        write(2, "\n", 1);
    }
}

void continue_check_for_programm_execution(main_info_t *infos,
    char *found_path, char **word_array)
{
    struct stat s;
    int status = 0;
    int wpid;
    int exec_value = 84;

    if (check_if_file_is_dir(found_path) == 1)
        return;
    if (stat(found_path, &s) == 0 && (s.st_mode & S_IXUSR)) {
        if (fork() == 0)
            exec_value = execve(found_path, word_array, infos->envp);
        if (exec_value == -1) {
            handle_execve_error(word_array[0]);
            return;
        }
        while ((wpid = wait(&status)) > 0);
        handle_signals(status);
    } else {
        my_perror(word_array[0]);
        my_perror(": Permissions denied.\n");
    }
}

void search_program(main_info_t *infos, char **word_array)
{
    char *found_path = search_path(infos, word_array);

    if (my_strcmp(found_path, "N/A") != 0) {
        continue_check_for_programm_execution(infos, found_path, word_array);
    } else {
        my_perror(word_array[0]);
        my_perror(": Command not found.\n");
    }
}

void handle_other_commands(main_info_t *infos, char **word_array)
{
    if (word_array[0][0] != '/')
        search_program(infos, word_array);
    else
        continue_check_for_programm_execution(infos, word_array[0], word_array);
}