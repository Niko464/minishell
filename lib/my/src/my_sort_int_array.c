/*
** EPITECH PROJECT, 2019
** my_sort_int_array
** File description:
** no desc
*/

#include "my.h"

int *my_sort(int *tab, int longueur)
{
    int temp;
    for (int j = 1; j < longueur; j++) {
        if ((tab[j - 1] - tab[j]) > 0) {
            temp = tab[j - 1];
            tab[j - 1] = tab[j];
            tab[j] = temp;
        }
    }
    return tab;
}

void my_sort_int_array(int *array, int size)
{
    for (int i = 0; i < size; i++) {
        array = my_sort(array, size);
    }
    for (int i = 0; i < size; i++) {
        my_put_nbr(array[i]);
        my_putchar('\n');
    }
}