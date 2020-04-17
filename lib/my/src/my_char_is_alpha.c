/*
** EPITECH PROJECT, 2019
** my_char_is_alpha.c
** File description:
** no description
*/

#include "my.h"

int my_char_is_alpha(char c)
{
    if ((c < 91 && c > 64) || (c < 123 && c > 96))
        return 1;
    return 0;
}