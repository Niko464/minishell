/*
** EPITECH PROJECT, 2019
** my_perror
** File description:
** displays an error
*/

#include "my.h"
#include <unistd.h>

void my_perror(char *str)
{
    write(2, str, my_strlen(str));
}