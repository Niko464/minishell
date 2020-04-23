/*
** EPITECH PROJECT, 2020
** remove_spaces.c
** File description:
** This is the main file for the project
*/

#include "my.h"
#include <stdlib.h>

int spec_count_separators(char *str)
{
    int words = 0;
    int found_letter = 0;
    for (int i = 0; i < my_strlen(str); i++) {
        if (spec_is_separator(str, my_strlen(str), i, &found_letter) == 1)
            words++;
    }
    return words + 1;
}

int spec_is_separator(char *str, int len_str, int i,
    int *found_letter)
{
    if (str[i] == ' ' &&
        str[i + 1] != ' ' &&
        i != len_str - 1 &&
        *found_letter != 0) {
        return 1;
    } else
        *found_letter += 1;
    return 0;
}

int is_not_banned_char(char c)
{
    if (c == '\t' || c == ' ' || c == '\0')
        return 0;
    return 1;
}

void special_check(char c, char *result, int counter)
{
    if (c == '\t') {
        result[counter] = ' ';
    } else {
        result[counter] = c;
    }
}

char *my_remove_spaces(char *str)
{
    char *result = malloc(sizeof(char) * (my_strlen(str) + 1));
    int counter = 0;
    int found_letter = 0;

    for (int i = 0; i < my_strlen(str); i++) {
        if (is_not_banned_char(str[i]) == 1)
            found_letter = 1;
        if (is_not_banned_char(str[i]) == 1 ||
            (is_not_banned_char(str[i]) == 0 &&
            is_not_banned_char(str[i + 1]) == 1) &&
            (found_letter == 1)) {
            special_check(str[i], result, counter);
            counter += 1;
            result[counter] = '\0';
        }
    }
    if (result[my_strlen(result) - 1] == ' ')
        result[my_strlen(result) - 1] = '\0';
    return result;
}