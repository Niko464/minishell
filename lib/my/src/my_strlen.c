/*
** EPITECH PROJECT, 2019
** my_strlen
** File description:
** counts and returns number of characters found in the string
*/

#include "my.h"

int my_strlen(char const *str)
{
    int length = 0;

    while (str[length] != '\0')
        length++;
    return length;
}