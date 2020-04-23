/*
** EPITECH PROJECT, 2020
** expression_handling.c
** File description:
** This file handles a list of commands
*/

#include "my.h"
#include "mini_shell.h"
#include <stdlib.h>
#include <stdio.h>

void handle_redirect_input_double(main_info_t *infos, char **command,
    int expr_position)
{
    int nbr_args = 0;
    char **to_send = NULL;

    for (int i = 0; command[i] != 0; i++)
        nbr_args++;
    if (check_errors_redirect_input_double(nbr_args,
        expr_position) != 0) {
        return;
    }
    to_send = get_redirect_input(command[expr_position + 1]);
    if (to_send == NULL)
        return;
    char **new_command = remove_arg_from_command(command, expr_position);
    new_command = remove_arg_from_command(new_command, expr_position);
    handle_command_redirect_left(infos, new_command, to_send);
}

char **get_redirect_input(char *end)
{
    char *input = malloc(sizeof(char) * 15);
    char *save = mem_set(1);
    char *save_two = NULL;
    int nbr_words = 0;
    size_t size = 14;
    do {
        my_putstr("? ");
        input = malloc(sizeof(char) * 15);
        if (getline(&input, &size, stdin) == -1)
            break;
        input = my_str_trim(input, 1);
        save_two = my_strdup(save);
        save = concat_with_char(save_two, input, '}');
        nbr_words++;
    } while (my_strcmp(input, end) != 0);
    save = my_cut_string(save, 0, my_get_index_char(save, '}',
        nbr_words));
    return get_return_and_seperate_char(save);
}

char **get_return_and_seperate_char(char *str)
{
    int nbr_words = my_count_char(str, '}') - 1;
    char **to_return = malloc(sizeof(char *) * (nbr_words + 1));
    char *curr_word = NULL;
    int begin = 0;
    int end = 0;

    for (int i = 0; i < nbr_words; i++) {
        begin = my_get_index_char(str, '}', i + 1) + 1;
        end = my_get_index_char(str, '}', i + 2) - 1;
        curr_word = my_cut_string(str, begin, end);
        curr_word[my_strlen(curr_word)] = '\0';
        to_return[i] = malloc(sizeof(char) * my_strlen(curr_word));
        to_return[i] = curr_word;
    }
    to_return[nbr_words] = 0;
    return to_return;
}