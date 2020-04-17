/*
** EPITECH PROJECT, 2020
** paths.c
** File description:
** This is a file for minshell
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "mini_shell.h"

void set_first_path(main_info_t *infos, char *curr_path)
{
    int end = my_strlen(curr_path) + 1;
    char *first_path = NULL;

    if (my_get_index_char(curr_path, ':', 1) != -1)
        end = my_get_index_char(curr_path, ':', 1);
    first_path = my_cut_string(curr_path, 5, end - 1);
    infos->paths[0] = malloc(sizeof(char) * (my_strlen(first_path) + 1));
    infos->paths[0] = first_path;
}

void set_middle_paths(main_info_t *infos, int nbr_paths, char *curr_path)
{
    char *loop_path = NULL;
    int len_loop_path = 0;

    for (int i = 1; i < nbr_paths - 1; i++) {
        loop_path = my_cut_string(curr_path,
            my_get_index_char(curr_path, ':', i) + 1,
            my_get_index_char(curr_path, ':', i + 1) - 1);
        len_loop_path = my_strlen(loop_path);
        infos->paths[i] = malloc(sizeof(char) * (len_loop_path + 1));
        infos->paths[i] = loop_path;
    }
}

void set_last_path(main_info_t *infos, int nbr_paths, char *curr_path)
{
    char *last_path = my_cut_string(curr_path,
        my_get_index_char(curr_path, ':', nbr_paths - 1) + 1,
        my_strlen(curr_path));
    infos->paths[nbr_paths - 1] = malloc(sizeof(char) *
        (my_strlen(last_path) + 1));
    infos->paths[nbr_paths - 1] = last_path;
}

void update_paths(main_info_t *infos)
{
    for (int i = 0; infos->paths[i] != 0; i++)
        free(infos->paths[i]);
    free(infos->paths);
    for (int i = 0; infos->envp[i] != 0; i++)
        try_put_env_in_paths(infos, infos->envp[i]);
}