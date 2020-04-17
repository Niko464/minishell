/*
** EPITECH PROJECT, 2019
** my_strncpy
** File description:
** copies a string into another given a parameter n
*/

#include "my.h"

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;
    int length = my_strlen(src);

    while (n > 0) {
        if (n < length) {
            dest[i] = src[i];
        } else {
            dest[i] = '\0';
        }
        n--;
        i++;
    }
    return dest;
}