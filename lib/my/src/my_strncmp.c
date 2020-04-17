/*
** EPITECH PROJECT, 2019
** my_strncmp
** File description:
** compares two strings
*/

#include "my.h"

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;
    int n_save = n;
    char s1_value;
    char s2_value;

    while (s1[i] == s2[i]) {
        if (n > 0) {
            n--;
            i++;
        }
    }
    s1_value = s1[i];
    s2_value = s2[i];
    if ((i - 1 == my_strlen(s1) && i - 1 == my_strlen(s2)) || (i == n_save)) {
        return 0;
    }
    if (s1_value != s2_value) {
        return s1_value - s2_value;
    }
    return 0;
}