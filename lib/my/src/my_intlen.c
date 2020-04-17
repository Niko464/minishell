/*
** EPITECH PROJECT, 2019
** my_intlen.c
** File description:
** this function returns the length of an int
*/

#include "my.h"

int my_intlen(int nb)
{
    int i = 0;
    if (nb < 0)
        nb *= -1;
    else if (nb == 0)
        return (1);
    while (nb > 0) {
        i++;
        nb /= 10;
    }
    return i;
}