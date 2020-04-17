/*
** EPITECH PROJECT, 2019
** my_put_nbr_base.c
** File description:
** this transforms a number into any base
*/

#include "my.h"
#include "my_printf.h"
#include <stdlib.h>

void my_put_nbr_base(unsigned long long int to_change, char *base)
{
    int length = my_strlen(base);

    if (to_change < 0) {
        to_change = to_change * -1;
        my_putchar('-');
    }
    if (to_change > length - 1)
        my_put_nbr_base(to_change / length, base);
    my_putchar(base[to_change % length]);
}