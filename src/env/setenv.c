/*
** EPITECH PROJECT, 2020
** env.c
** File description:
** This is the file that handles the env command
*/

#include <stdlib.h>
#include "my.h"
#include "mini_shell.h"

char *try_to_find_env_var(char *to_find, char *curr_test,
    int var_name_len)
{
    char *test = my_cut_string(curr_test, 0, var_name_len - 1);

    if (my_strcmp(test, to_find) == 0) {
        test[var_name_len] = '\0';
        return test;
    }
    return "N/A\0";
}

char *get_new_var_name(char **word_array, int nbr_args)
{
    int total_len = (my_strlen(word_array[1]) + 2);
    char *new_var = NULL;

    if (nbr_args == 3)
        total_len = (my_strlen(word_array[1]) + my_strlen(word_array[2]) + 2);
    new_var = malloc(sizeof(char) * total_len);
    my_strcat(new_var, word_array[1]);
    my_strcat(new_var, "=\0");
    if (nbr_args == 3)
        my_strcat(new_var, word_array[2]);
    new_var[total_len - 1] = '\0';
    return new_var;
}

void continue_setenv_checks_follow_up(main_info_t *infos,
    char **word_array, int nbr_args)
{
    if (my_strcmp(word_array[1], "PATH") == 0)
        infos->is_path_unset = 0;
    set_new_env_name_variable(infos, word_array, nbr_args);
}

void continue_setenv_checks(main_info_t *infos, char **word_array, int nbr_args)
{
    if (my_char_is_alpha(word_array[1][0]) == 1) {
        if (my_str_aplha_or_int(word_array[1]) == 1) {
            continue_setenv_checks_follow_up(infos, word_array, nbr_args);
        } else {
            my_perror(word_array[0]);
            my_perror(": Variable name must contain alphanumeric");
            my_perror(" characters.\n");
        }
    } else {
        my_perror(word_array[0]);
        my_perror(": Variable name must begin with a letter.\n");
    }
}

void handle_setenv(main_info_t *infos, char **word_array)
{
    int nbr_args = 0;
    for (int i = 0; word_array[i] != 0; i++)
        nbr_args++;
    if (nbr_args >= 2) {
        if (nbr_args == 3 || nbr_args == 2) {
            continue_setenv_checks(infos, word_array, nbr_args);
        } else {
            my_perror(word_array[0]);
            my_perror(": Too many arguments.\n");
        }
    } else {
        handle_env(infos);
    }
}