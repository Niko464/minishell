/*
** EPITECH PROJECT, 2019
** my_swap
** File description:
** swaps vales between variables
*/

#include "my.h"

void my_swap(int *a, int *b)
{
    int temp_b = *b;

    *b = *a;
    *a = temp_b;
}
