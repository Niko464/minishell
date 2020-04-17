/*
** EPITECH PROJECT, 2020
** shell_manager.c
** File description:
** This is a file for the project
*/

#include <stdlib.h>
#include <signal.h>
#include "my.h"
#include "mini_shell.h"

int terminate_shell(main_info_t *infos)
{
    int to_return = infos->return_value;
    free(infos);
    return to_return;
}

int launch_main_loop(main_info_t *infos)
{
    while (infos->shell_state == USING) {
        if (ask_input(infos) == 1)
            return (0);
    }
    return (terminate_shell(infos));
}