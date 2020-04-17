/*
** EPITECH PROJECT, 2019
** my_str_to_int.c
** File description:
** str = check_string_is_number(str);
*/

#include "my.h"
#include <stdlib.h>

int my_str_to_int(char *str)
{
    int length = my_strlen(str);
    int res = 0;
    int offset = 0;
    if (str[0] == '-') {
        offset++;
        length--;
    }
    for (int i = 0; i < length; i++) {
        res += my_compute_power_rec(10, length - i - 1) *
            (str[i + offset] - 48);
    }
    if (offset == 1)
        res *= -1;
    return res;
}