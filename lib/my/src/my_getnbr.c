/*
** EPITECH PROJECT, 2019
** getnbr
** File description:
** no desc
*/

#include "my.h"
#include <stdlib.h>

int my_getnbr(char const *str)
{
    str = my_check_string_is_number(str);
    int sign = my_get_sign(str);
    int offset = 0;
    int res = 0;
    int index = 0;

    if (str == "")
        return 0;
    if (sign == '-')
        offset = 1;
    for (int c = offset; str[c] != '\0'; c++) {
        index++;
        res = res * 10 + str[c] - 48;
        if (index > 10)
            return 0;
    }
    if (sign == '-')
        res = -res;
    return res;
}