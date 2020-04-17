/*
** EPITECH PROJECT, 2019
** my_putchar
** File description:
** displays something
*/

#include "my.h"
#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}