/*
** EPITECH PROJECT, 2020
** setenv_two.c
** File description:
** This is the file that handles the setenv command
*/

#include <stdlib.h>
#include "my.h"
#include "mini_shell.h"

void set_new_env_name_variable_follow_up(main_info_t *infos, int bool_exists,
    int i, char *new_var)
{
    if (bool_exists == 0) {
        infos->envp[i] = malloc(sizeof(char) * my_strlen(new_var));
        infos->envp[i] = new_var;
        infos->envp[i + 1] = 0;
    }
    if (infos->is_path_unset == 0)
        update_paths(infos);
}

void set_new_env_name_variable(main_info_t *infos, char **word_array,
    int nbr_args)
{
    int var_name_len = my_strlen(word_array[1]);
    char *new_var = get_new_var_name(word_array, nbr_args);
    char *found_var = malloc(sizeof(char) * my_strlen(word_array[1]) + 1);
    int bool_exists = 0;
    int i = 0;

    for (; infos->envp[i] != 0; i++) {
        found_var = try_to_find_env_var(word_array[1],
            my_strdup(infos->envp[i]), var_name_len);
        if (my_strcmp(found_var, "N/A\0") != 0) {
            infos->envp[i] = new_var;
            bool_exists = 1;
        }
    }
    set_new_env_name_variable_follow_up(infos, bool_exists, i, new_var);
}