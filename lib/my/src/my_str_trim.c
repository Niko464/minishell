/*
** EPITECH PROJECT, 2020
** my_str_trim.c
** File description:
** This is the file that handles dir stuff for my_ls
*/

#include <stdlib.h>
#include "my.h"

char *my_str_trim(char *str, int nbr_chars)
{
    int len = my_strlen(str);
    char *result = malloc(sizeof(char) * (len - nbr_chars + 1));
    int i = 0;
    for (; i < len - nbr_chars; i++)
        result[i] = str[i];
    result[i] = '\0';
    free(str);
    return result;
}