/*
** EPITECH PROJECT, 2019
** add_zeros_to_char.c
** File description:
** this adds a number of zeros to the end of a string
*/

#include "my.h"
#include "my_printf.h"
#include <stdlib.h>

char *add_zeros_to_char(char *str, int nb_zeros)
{
    char *res = malloc(sizeof(char) * (my_strlen(str) + nb_zeros + 1));

    my_strcpy(res, str);
    for (int i = 0; i < nb_zeros; i++) {
        my_strcat(res, "0");
    }
    my_strcat(res, "\0");
    free(str);
    return (res);
}