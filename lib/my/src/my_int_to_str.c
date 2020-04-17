/*
** EPITECH PROJECT, 2019
** my_int_to_str.c
** File description:
** this function returns an str from an int
*/

#include "my.h"
#include <stdlib.h>

char *my_int_to_str(int nb)
{
    int len = my_intlen(nb);
    int div = 1;
    char *result = malloc(sizeof(char) * (len + 2));
    int i = 0;

    if (nb < 0) {
        nb *= -1;
        result[len] = '-';
    }
    if (nb == 0)
        return "0";
    for (i = 0; i < len; i++) {
        result[i] = (((nb / div) % 10) + 48);
        div *= 10;
    }
    result[i] = '\0';
    my_revstr(result);
    return result;
}