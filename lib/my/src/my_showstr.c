/*
** EPITECH PROJECT, 2019
** my_showstr.c
** File description:
** no description
*/

#include "my.h"

int my_showstr(char const *str)
{
    char c = 0;

    for (int i = 0; i < my_strlen(str); i++) {
        c = str[i];
        if (c < 127 && c >= 32)
            my_putchar(c);
        else
            my_putchar('.');
    }
    return 0;
}