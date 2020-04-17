/*
** EPITECH PROJECT, 2020
** utils.c
** File description:
** This is the file that handles dir stuff for my_ls
*/

#include <stdlib.h>
#include "my.h"

char *concat(char *s1, char *s2)
{
    char *result = malloc(sizeof(char) * (my_strlen(s1) + my_strlen(s2) + 2));
    int offset = 0;

    for (int i = 0; i < my_strlen(s1); i++, offset++)
        result[offset] = s1[i];
    for (int i = 0; i < my_strlen(s2); i++, offset++)
        result[offset] = s2[i];
    result[offset] = '\0';
    return result;
}