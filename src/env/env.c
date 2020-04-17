/*
** EPITECH PROJECT, 2020
** env.c
** File description:
** This is the file that handles the env command
*/

#include <stdlib.h>
#include "my.h"
#include "mini_shell.h"

void handle_env(main_info_t *infos)
{
    for (int i = 0; infos->envp[i] != 0; i++) {
        my_putstr(infos->envp[i]);
        my_putchar('\n');
    }
}

void change_env(main_info_t *infos, char *to_change, char *new_env)
{
    int len = my_strlen(to_change);
    int total_len = len + 2 + my_strlen(new_env);
    char *test = malloc(sizeof(char) * (len + 1));
    char *new_var = malloc(sizeof(char) * total_len);

    my_strcat(new_var, to_change);
    my_strcat(new_var, "=\0");
    my_strcat(new_var, new_env);
    new_var[total_len - 1] = '\0';
    for (int i = 0; infos->envp[i] != 0; i++) {
        test = my_cut_string(infos->envp[i], 0, len - 1);
        if (my_strcmp(test, to_change) == 0) {
            infos->envp[i] = new_var;
        }
    }
}