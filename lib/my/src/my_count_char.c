/*
** EPITECH PROJECT, 2019
** my_count_char.c
** File description:
** counts the nbr of times a char is in a str
*/

#include "my.h"

int my_count_char(char const *str, char c)
{
    int count = 0;
    for (int i = 0; i < my_strlen(str); i++) {
        if (str[i] == c)
            count++;
    }
    return (count);
}