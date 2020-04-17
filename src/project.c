/*
** EPITECH PROJECT, 2020
** project.c
** File description:
** This is a file for the project
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "mini_shell.h"

int start_mini_shell(char **envp)
{
    main_info_t *infos = NULL;
    infos = init_shell(envp);
    return (launch_main_loop(infos));
}