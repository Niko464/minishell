/*
** EPITECH PROJECT, 2019
** my_print_octal.c
** File description:
** this prints a number in octal
*/

#include "my.h"
#include "my_printf.h"
#include <stdlib.h>

void my_put_str_with_octal_form(char *str)
{
    for (int i = 0; i < my_strlen(str); i++) {
        if (str[i] < 127 && str[i] >= 32)
            my_putchar(str[i]);
        else {
            int to_change = str[i];
            my_putchar('\\');
            my_print_octal(to_change, 8);
        }
    }
}

void my_print_octal(int to_change, int new_base)
{
    char *res = malloc(sizeof(char) * 15);
    int div = to_change;
    int whats_left = 0;
    int index = 0;

    while (div != 0) {
        whats_left = div % new_base;
        div = div / new_base;
        res[index] = whats_left + 48;
        index++;
    }
    if (my_strlen(res) < 3)
        res = add_zeros_to_char(res, 3 - my_strlen(res));
    my_putstr(my_revstr(res));
    free(res);
}