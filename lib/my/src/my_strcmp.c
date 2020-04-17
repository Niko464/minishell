/*
** EPITECH PROJECT, 2019
** my_strcpy
** File description:
** copies a string into another
*/

#include "my.h"

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;
    char s1_length = my_strlen(s1);
    char s2_length = my_strlen(s2);
    char s1_value;
    char s2_value;

    while (s1[i] == s2[i] && (s1[i] != '\0' && s2[i] != '\0'))
        i++;
    if (i - 1 == s1_length && i - 1 == s2_length)
        return 0;
    s1_value = s1[i];
    s2_value = s2[i];
    if (s1_value != s2_value)
        return s1_value - s2_value;
    return 0;
}