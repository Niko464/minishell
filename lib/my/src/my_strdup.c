/*
** EPITECH PROJECT, 2019
** my_strdup
** File description:
** puts a string into upper cases
*/

#include <stdlib.h>
#include "my.h"

char *my_strdup(char const *src)
{
    char *result = malloc(sizeof(char) * (my_strlen(src) + 1));
    int i = 0;

    while (i < my_strlen(src)) {
        result[i] = src[i];
        i++;
    }
    result[i] = '\0';
    return result;
}