/*
** EPITECH PROJECT, 2019
** concat_params
** File description:
** shows an array of words
*/

#include <stdlib.h>
#include "my.h"

char **my_str_to_word_array(char const *str)
{
    int total_words = my_count_char(str, ' ') + 1;
    char **result = malloc(sizeof(char *) * (total_words + 1));
    int words = 0;
    int start_new_word = 0;
    char *new_word = NULL;

    for (int i = 0; i < my_strlen(str); i++) {
        if (str[i] == ' ' && i != 0) {
            words++;
            start_new_word = i + 1;
        } else {
            new_word = my_cut_string(str, start_new_word, i);
            result[words] = malloc(sizeof(char) * my_strlen(new_word) + 1);
            result[words] = my_strdup(new_word);
            result[words][my_strlen(new_word)] = '\0';
            free(new_word);
        }
    }
    result[total_words] = 0;
    return result;
}