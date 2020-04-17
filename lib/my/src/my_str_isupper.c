/*
** EPITECH PROJECT, 2019
** my_str_isupper.c
** File description:
** no description
*/

#include "my.h"

int my_str_isupper(char const *str)
{
    char c = 0;
    int index = 0;
    int length = my_strlen(str);

    for (int i = 0; i < length; i++) {
        c = str[i];
        if (c < 91 && c > 64)
            index++;
        if (str[i] == ' ')
            index++;
    }
    if (index == length)
        return 1;
    return 0;
}