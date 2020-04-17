/*
** EPITECH PROJECT, 2019
** utils.c
** File description:
** this is a file that contains usefull functions for my_printf
*/

#include "my.h"
#include "my_printf.h"
#include <stdarg.h>

int get_index_char(char *str, char c, int occurence)
{
    int index = 0;

    for (int i = 0; i < my_strlen(str); i++) {
        if (str[i] == c && str[i + 1] != '%')
            index++;
        if (index == occurence)
            return i;
    }
    return (-1);
}

int count_nbr_percentages(char *str)
{
    int count = 0;

    for (int i = 0; i < my_strlen(str); i++) {
        if (str[i] == '%' && str[i + 1] != '%')
            count++;
    }
    return count;
}

char *get_base_for_print(char c)
{
    if (c == 'b')
        return "01";
    else if (c == 'o')
        return "01234567";
    if (c == 'X')
        return "0123456789ABCDEF";
    return "0123456789abcdef";
}