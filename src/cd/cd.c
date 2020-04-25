/*
** EPITECH PROJECT, 2020
** cd.c
** File description:
** This is the file that handles the cd command
*/

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <dirent.h>
#include "my.h"
#include "mini_shell.h"

void enter_directory(main_info_t *infos, char *path)
{
    char buffer[100];
    getcwd(buffer, 100);
    infos->last_dir = concat_slash(buffer, "");
    chdir(path);
    getcwd(buffer, 100);
    change_env(infos, "PWD", buffer);
}

void go_home_dir(main_info_t *infos, char *home_path)
{
    char buffer[100];
    getcwd(buffer, 100);
    infos->last_dir = concat_slash(buffer, "");
    chdir(home_path);
    getcwd(buffer, 100);
    change_env(infos, "PWD", buffer);
}

int go_last_dir(main_info_t *infos, char **word_array)
{
    char buffer[100];
    char *save = infos->last_dir;

    if (my_strcmp(word_array[1], "-") == 0) {
        if (my_strcmp(infos->last_dir, "") != 0) {
            getcwd(buffer, 100);
            infos->last_dir = concat_slash(buffer, "");
            chdir(save);
            getcwd(buffer, 100);
            change_env(infos, "PWD", buffer);
        } else
            my_perror(": No such file or directory\n");
        return (0);
    }
    return (1);
}

void try_enter_dir(main_info_t *infos, char **word_array)
{
    DIR *dir = opendir(word_array[1]);
    struct stat s;

    if (go_last_dir(infos, word_array) != 0) {
        if (dir != NULL)
            enter_directory(infos, word_array[1]);
        else if (lstat(word_array[1], &s) == 0) {
            my_perror(word_array[1]);
            my_perror(": Not a directory.\n");
        } else {
            my_perror(word_array[1]);
            my_perror(": No such file or directory\n");
        }
    }
}

void handle_cd(main_info_t *infos, char **word_array)
{
    int nbr_args = 0;
    for (; word_array[nbr_args] != 0; nbr_args++);
    if (nbr_args > 2)
        my_perror("cd: Too many arguments.\n");
    else if (nbr_args == 1)
        go_home_dir(infos, infos->home_path);
    else
        try_enter_dir(infos, word_array);
}