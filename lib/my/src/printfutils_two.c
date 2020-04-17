/*
** EPITECH PROJECT, 2019
** printfutils_two.c
** File description:
** this is the second file that contains usefull functions for my_printf
*/

#include "my.h"
#include "my_printf.h"
#include <stdarg.h>

void hashtag_octal(unsigned long long int nbr)
{
    my_putstr("0");
    my_put_nbr_base(nbr, "01234567");
}

void hastag_hexa_min(unsigned long long int nbr)
{
    my_putstr("0x");
    my_put_nbr_base(nbr, "0123456789abcdef");
}

void hashtag_hexa_maj(unsigned long long int nbr)
{
    my_putstr("0X");
    my_put_nbr_base(nbr, "0123456789ABCDEF");
}