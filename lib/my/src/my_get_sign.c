/*
** EPITECH PROJECT, 2019
** my_get_sign
** File description:
** gets the sign of a string
*/

#include "my.h"

char my_get_sign(char const *str)
{
    int i = 0;
    int nb_min = 0;
    int boolean = 0;
    char sign = '+';

    while (str[i] != '\0') {
        if ((str[i] == '-') && (boolean == 0))
            nb_min++;
        else if ((str[i] == '+') && (boolean == 0))
            boolean = 0;
        else
            boolean = 1;
        i++;
    }
    if (nb_min % 2 != 0)
        sign = '-';
    return sign;
}