/*
** EPITECH PROJECT, 2019
** my_strcat.c
** File description:
** no description
*/

#include "my.h"

char *my_strcat(char *dest, char const *src)
{
    int length_dest = my_strlen(dest);
    int length_src = my_strlen(src);

    for (int i = 0; i < length_src + 1; i++) {
        dest[i + length_dest] = src[i];
    }
    return dest;
}