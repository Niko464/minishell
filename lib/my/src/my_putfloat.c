/*
** EPITECH PROJECT, 2019
** my_putfloat.c
** File description:
** this prints a float number
*/

#include "my.h"

void my_putfloat(float my_float, int nbr)
{
    int integer = 0;

    if (my_float < 0) {
        my_putchar('-');
        my_float *= -1;
    }
    integer = my_float;
    my_put_nbr(integer);
    my_putchar('.');
    integer = (my_float - integer) * (my_compute_power_rec(10, nbr));
    my_put_nbr(integer);
}