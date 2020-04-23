/*
** EPITECH PROJECT, 2019
** my_str_to_float.c
** File description:
** str = check_string_is_number(str);
*/

#include "my.h"
#include <stdlib.h>

float my_str_to_float(char *str)
{
    int length = my_strlen(str);
    float res = 0.0;
    float dec = 1.0;
    int offset = 0;
    int i = 0;
    (str[0] == '-') ? offset++, length-- : 0;
    for (; i < length; i++) {
        if (str[i] == '.')
            break;
        res += (str[i + offset] - 48);
        res *= 10;
    }
    res /= 10;
    i += 1;
    for (; i < length; i++) {
        dec *= 10;
        res += ((str[i + offset] - 48) / dec);
    }
    (offset == 1) ? res *= -1 : 0;
    return res;
}