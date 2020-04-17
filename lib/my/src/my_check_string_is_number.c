/*
** EPITECH PROJECT, 2019
** my_check_string_is_number.c
** File description:
** this functions checks if a string is a nbr
*/

#include "my.h"
#include <stdlib.h>

char *my_check_string_is_number(char const *str)
{
    char *res = malloc(sizeof(char) * (my_strlen(str) + 1));
    int i = 0;
    int boolean = 0;
    int offset = 0;
    int nb_op = my_get_nbr_operators(str);

    if (my_get_sign(str) == '-') {
        res[0] = '-';
        offset++;
    }
    while (str[i + nb_op] != '\0') {
        if (str[i + nb_op] < 58 && str[i + nb_op] > 47 && boolean == 0)
            res[i + offset] = str[i + nb_op];
        else
            boolean = 1;
        i++;
    }
    return res;
}