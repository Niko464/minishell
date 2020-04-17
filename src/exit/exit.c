/*
** EPITECH PROJECT, 2020
** exit.c
** File description:
** This is the file that handles the exit command
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "my.h"
#include "mini_shell.h"

void handle_exit_with_args(main_info_t *infos, char **word_array)
{
    int return_value = 0;

    if (my_str_isnum(word_array[1])) {
        infos->shell_state = EXITING;
        my_putstr("exit\n");
        return_value = my_str_to_int(word_array[1]);
        if (return_value > 0 && return_value <= 255)
            infos->return_value = return_value;
        else if (return_value == 256)
            infos->return_value = 0;
        else if (return_value == 257)
            infos->return_value = 1;
        else
            infos->return_value = (return_value & 0xFF);
    } else {
        my_perror(word_array[0]);
        my_perror(": Expression Syntax.\n");
    }
}

void handle_exit(main_info_t *infos, char **word_array)
{
    int nbr_args = 0;

    for (int i = 0; word_array[i] != 0; i++)
        nbr_args++;
    if (nbr_args == 1) {
        infos->shell_state = EXITING;
        my_putstr("exit\n");
        infos->return_value = 0;
        return;
    } else {
        handle_exit_with_args(infos, word_array);
    }
}