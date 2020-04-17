/*
** EPITECH PROJECT, 2020
** env.c
** File description:
** This is the file that handles the env command
*/

#include <stdlib.h>
#include "my.h"
#include "mini_shell.h"

void remove_env(main_info_t *infos, int j)
{
    int offset = 0;
    for (int i = 0; infos->envp[i] != 0; i++) {
        if (i == j)
            offset++;
        infos->envp[i] = infos->envp[i + offset];
    }
}

void try_removing_from_env(main_info_t *infos, char *str)
{
    int var_name_len = my_strlen(str);
    char *found_var = malloc(sizeof(char) * (var_name_len + 1));
    int i = 0;

    for (; infos->envp[i] != 0; i++) {
        found_var = try_to_find_env_var(str, my_strdup(infos->envp[i]),
            var_name_len);
        if (my_strcmp(found_var, "N/A\0") != 0)
            remove_env(infos, i);
        if (my_strcmp(found_var, "PATH\0") == 0) {
            infos->is_path_unset = 1;
        }
    }
}

void remove_list_of_envs(main_info_t *infos, char **word_array)
{
    for (int i = 1; word_array[i] != 0; i++) {
        if (my_str_aplha_or_int(word_array[1]) == 1)
            try_removing_from_env(infos, word_array[i]);
    }
}

void handle_unsetenv(main_info_t *infos, char **word_array)
{
    int nbr_args = 0;
    for (int i = 0; word_array[i] != 0; i++)
        nbr_args++;
    if (nbr_args > 1) {
        remove_list_of_envs(infos, word_array);
    } else {
        my_perror(word_array[0]);
        my_perror(": Too few arguments.\n");
    }
}