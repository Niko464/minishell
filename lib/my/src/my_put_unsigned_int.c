/*
** EPITECH PROJECT, 2019
** my_put_unsigned_int
** File description:
** displays anything you giv it as parameter
*/

#include "my.h"
#include "my_printf.h"
#include <stdio.h>

void my_put_unsigned_int(unsigned int nb)
{
    long long p = 1;

    if (nb < 0) {
        my_putchar('-');
        nb *= -1;
    }
    while ((nb / p) != 0) {
        p = p * 10;
    }
    if (nb == 0)
        my_putchar('0');
    while (p != 1) {
        long long digit = ((nb % p) / (p / 10));
        my_putchar(digit + 48);
        p = p / 10;
    }
}