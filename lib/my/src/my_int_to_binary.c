/*
** EPITECH PROJECT, 2020
** my_int_to_binary.c
** File description:
** This is file handles binary stuff
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"

char *my_int_to_binary(int my_int)
{
    char *result = NULL;
    int int_array[10];
    int i = 0;
    int iterator = 0;

    for (i = 0; my_int > 0; i++) {
        int_array[i] = my_int % 2;
        my_int = my_int/2;
    }
    result = mem_set(i + 1);
    for (i = i - 1; i >= 0; i--, iterator++)
        result[iterator] = int_array[i] + 48;
    result[iterator] = '\0';
    return result;
}