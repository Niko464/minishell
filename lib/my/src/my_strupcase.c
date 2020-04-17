/*
** EPITECH PROJECT, 2019
** my_strupcase
** File description:
** puts a string into upper cases
*/

#include "my.h"

char *my_strupcase(char *str)
{
    char c = 0;

    for (int i = 0; i < my_strlen(str); i++) {
        c = str[i];
        if (c > 91)
            c -= 32;
        str[i] = c;
    }
}