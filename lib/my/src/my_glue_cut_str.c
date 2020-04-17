/*
** EPITECH PROJECT, 2019
** my_putchar
** File description:
** displays something
*/

#include <stdlib.h>
#include "my.h"

char *my_glue_cut_str(char *str1, char *str2, int start_str_2, int end_str2)
{
    int len_str1 = my_strlen(str1);
    int len_str2 = end_str2 - start_str_2 + 1;
    int len_result = (len_str1 + len_str2 + 1);
    char *result = malloc(sizeof(char) * len_result);

    for (int i = 0; i < len_str1; i++)
        result[i] = str1[i];
    for (int j = 0; j < len_str2; j++)
        result[len_str1 + j] = str2[start_str_2 + j];
    result[len_result - 1] = '\0';
    return (result);
}