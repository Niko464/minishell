/*
** EPITECH PROJECT, 2019
** my_print_address
** File description:
** prints the address
*/

#include "my.h"
#include "my_printf.h"
#include <stdio.h>

int my_print_address(unsigned long long int nbr)
{
    my_putstr("0x");
    my_put_nbr_base(nbr, "0123456789abcdef");
    return (0);
}