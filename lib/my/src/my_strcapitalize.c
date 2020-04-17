/*
** EPITECH PROJECT, 2019
** my_strcapitalize
** File description:
** no desc
*/

#include "my.h"

void continue_str_capitalize(char *str, int i)
{
    char c = 0;

    if ((str[i] == ' ') || (str[i] == '+')
    || (str[i] == '-')) {
        c = str[i + 1];
        if (c > 91)
            c -= 32;
        str[i + 1] = c;
    }
    if (i == 0) {
        c = str[i];
        if (c > 91)
            c -= 32;
        str[i] = c;
    }
}

char *my_strcapitalize(char *str)
{
    for (int i = 0; i < my_strlen(str); i++) {
        continue_str_capitalize(str, i);
    }
    return str;
}