/*
** EPITECH PROJECT, 2019
** my_char_is_int.c
** File description:
** no description
*/

#include "my.h"

int my_char_is_int(char c)
{
    if ((c < 58 && c > 47))
        return 1;
    return 0;
}