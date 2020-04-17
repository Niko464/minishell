/*
** EPITECH PROJECT, 2019
** my_revstr
** File description:
** reverse a string
*/

#include "my.h"

char *my_revstr(char *str)
{
    char length = my_strlen(str) - 1;
    char a = length;
    char b = 0;

    while (b < a) {
        char temp = str[b];
        str[b] = str[a];
        str[a] = temp;
        b++;
        a--;
    }
    return str;
}