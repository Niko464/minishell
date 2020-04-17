/*
** EPITECH PROJECT, 2019
** my_cut_string.c
** File description:
** this function returns a specific part of a string
*/

#include "my.h"
#include <stdlib.h>

char *my_cut_string(char const *str, int start, int end)
{
    int i = 0;
    char *result;
    result = malloc(sizeof(char *) * (end - start + 1));
    while (start <= end) {
        result[i] = str[start];
        start++;
        i++;
    }
    result[i] = '\0';
    return result;
}