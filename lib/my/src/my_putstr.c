/*
** EPITECH PROJECT, 2019
** my_putstr
** File description:
** displays a string on the screen
*/

#include "my.h"

void my_putstr(char const *str)
{
    while (*str != '\0') {
        my_putchar((*str++));
    }
}
