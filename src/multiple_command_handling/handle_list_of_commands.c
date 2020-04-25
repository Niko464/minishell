/*
** EPITECH PROJECT, 2020
** handle_list_of_commands.c
** File description:
** This file handles a list of commands
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include "my.h"
#include "mini_shell.h"

char ***get_all_commands(char *line, int nbr_commands)
{
    char ***to_return = malloc(sizeof(char **) * (nbr_commands + 1));
    char *current_command = NULL;
    int begin = 0;
    int end = 0;

    for (int i = 0; i < nbr_commands; i++) {
        begin = my_get_index_char(line, ';', i) == 0 ?
            0 : my_get_index_char(line, ';', i) + 1;
        end = my_get_index_char(line, ';', i + 1) == -1 ?
            my_strlen(line) : my_get_index_char(line, ';', i + 1) - 1;
        current_command = my_cut_string(line, begin, end);
        current_command = my_remove_spaces(current_command);
        to_return[i] = my_str_to_word_array(current_command);
    }
    to_return[nbr_commands] = NULL;
    return to_return;
}

void handle_list_of_commands(main_info_t *infos, char *line)
{
    int line_len = my_strlen(line);
    int nbr_commands = my_count_char(line, ';');
    char ***list_of_commands = NULL;

    if (line_len - 1 != my_get_index_char(line, ';', nbr_commands) ||
        line_len == 1)
        nbr_commands++;
    if (line[0] == ';') {
        nbr_commands--;
        line = my_cut_string(line, 1, line_len);
    }
    list_of_commands = get_all_commands(line, nbr_commands);
    for (int i = 0; i < nbr_commands; i++) {
        if (does_command_contain_expression(infos, list_of_commands[i]) == 0 &&
            is_a_known_command(infos, list_of_commands[i]) == 0)
            handle_other_commands(infos, list_of_commands[i]);
    }
}