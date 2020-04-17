/*
** EPITECH PROJECT, 2019
** my_float_to_str.c
** File description:
** this prints a float number
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"

char *my_float_to_str(float my_float, int len_after_point)
{
    char *result = NULL;
    int integer = 0;
    int offset = 0;

    if (my_float < 0) {
        offset++;
        my_float *= -1;
    }
    result = mem_set((len_after_point + offset + 3));
    if (offset == 1)
        result[0] = '-';
    integer = my_float;
    my_strcat(result, my_int_to_str(integer));
    my_strcat(result, ".\0");
    integer = (my_float - integer) * (my_compute_power_rec(10,
        len_after_point));
    my_strcat(result, my_int_to_str(integer));
    result[(len_after_point + offset + 2)] = '\0';
    return result;
}