/*
** EPITECH PROJECT, 2019
** my_strncat.c
** File description:
** no description
*/

#include "my.h"

char *my_strncat(char *dest, char const *src, int nb)
{
    int length_dest = my_strlen(dest);
    int length_src = my_strlen(src);
    int i = 0;

    while (i < nb) {
        dest[i + length_dest] = src[i];
        i++;
    }
    if (i == nb) {
        dest[i + length_dest] = '\0';
    }
    return dest;
}