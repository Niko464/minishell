/*
** EPITECH PROJECT, 2019
** my_compute_power_rec
** File description:
** to the power with recusive function
*/

#include "my.h"

int my_compute_power_rec(int nb, int p)
{
    int nb2 = nb;

    if (p == 0) {
        return 1;
    } else if (p < 0) {
        return 0;
    }
    nb = nb * my_compute_power_rec(nb, p - 1);
    if (nb > 2147483647) {
        return 0;
    }
    return nb;
}
