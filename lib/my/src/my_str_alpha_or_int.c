/*
** EPITECH PROJECT, 2019
** my_str_alpha_or_int.c
** File description:
** no description
*/

#include "my.h"

int my_str_aplha_or_int(char *str)
{
    char c = 0;
    int index = 0;
    int length = my_strlen(str);

    for (int i = 0; i < length; i++) {
        c = str[i];
        if ((c < 58 && c > 47))
            index++;
        if ((c < 91 && c > 64) || (c < 123 && c > 96))
            index++;
        if (str[i] == ' ')
            index++;
    }
    if (index == length)
        return 1;
    return 0;
}