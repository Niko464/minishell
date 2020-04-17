/*
** EPITECH PROJECT, 2019
** mem_set
** File description:
** sts memory to a str
*/

#include "my.h"
#include <stdlib.h>

char *mem_set(int len)
{
    char *result = malloc(sizeof(char) * (len + 1));

    for (int i = 0; i < len; i++)
        result[i] = 0;
    result[len] = '\0';
    return (result);
}