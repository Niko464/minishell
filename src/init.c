/*
** EPITECH PROJECT, 2020
** init.c
** File description:
** This is a file for init minishell
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "mini_shell.h"

void try_getting_home_path(main_info_t *infos, char *curr_path)
{
    if (my_strcmp(my_cut_string(curr_path, 0, 3), "HOME") == 0)
        infos->home_path = my_cut_string(curr_path,
            my_get_index_char(curr_path, '=', 1) + 1, my_strlen(curr_path));
}

void try_put_env_in_paths(main_info_t *infos, char *curr_path)
{
    int nbr_paths = 0;
    char *test = my_cut_string(curr_path, 0, 3);

    if (my_strcmp(test, "PATH") == 0) {
        infos->entire_path = my_strdup(curr_path);
        nbr_paths = my_count_char(curr_path, ':') + 1;
        infos->paths = malloc(sizeof(char *) * ( nbr_paths + 1 ));
        set_first_path(infos, curr_path);
        if (nbr_paths != 1) {
            set_middle_paths(infos, nbr_paths, curr_path);
            set_last_path(infos, nbr_paths, curr_path);
        }
        infos->paths[nbr_paths] = 0;
    }
}

main_info_t *init_shell(char **envp)
{
    struct main_info *infos = malloc(sizeof(main_info_t));

    infos->shell_state = USING;
    infos->envp = envp;
    for (int i = 0; infos->envp[i] != 0; i++) {
        try_getting_home_path(infos, envp[i]);
        try_put_env_in_paths(infos, envp[i]);
    }
    infos->last_dir = "";
    infos->return_value = 0;
    infos->is_path_unset = 0;
    return (infos);
}