/*
** EPITECH PROJECT, 2019
** my_putlong.c
** File description:
** this prints a long number
*/

#include "my.h"
#include <unistd.h>

void my_putlong(long my_long)
{
    if (my_long < 0) {
        my_long *= -1;
        write(1, "-", 1);
    }
    if (my_long > 9) {
        my_putlong(my_long / 10);
        my_putlong(my_long % 10);
    } else {
        my_long = my_long + 48;
        write (1, &my_long, 1);
    }
}