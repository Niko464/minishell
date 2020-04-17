/*
** EPITECH PROJECT, 2019
** my_get_nbr_operators
** File description:
** gets the nbr of operators of a string
*/

#include "my.h"

int my_get_nbr_operators(char const *str)
{
    int i = 0;
    int nb_op = 0;
    int boolean = 0;

    while (str[i] != '\0') {
        if ((str[i] == '-') && (boolean == 0))
            nb_op++;
        else if ((str[i] == '+') && (boolean == 0))
            nb_op++;
        else
            boolean = 1;
        i++;
    }
    return nb_op;
}