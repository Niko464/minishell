/*
** EPITECH PROJECT, 2019
** my_compute_square_root
** File description:
** gives square root of smthing
*/

#include "my.h"

int my_compute_square_root(int nb)
{
    int test = 0;

    if (nb > 32767) {
        return 1;
    }
    while (test < nb) {
        if (test * test == nb) {
            return test;
        } else {
            test++;
        }
    }
    if (test == nb) {
        return 0;
    }
    return test;
}