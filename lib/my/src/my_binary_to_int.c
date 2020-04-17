/*
** EPITECH PROJECT, 2020
** my_binary_to_int.c
** File description:
** This is file handles binary stuff
*/

#include "my.h"

int my_binary_to_int(char *binary)
{
    int len = my_strlen(binary);
    int result = 0;

    for (int i = 0; i < len; i++) {
        result *= 2;
        if (binary[i] == '1')
            result += 1;
    }
    if (binary[0] == '-')
        result *= -1;
    return (result);
}