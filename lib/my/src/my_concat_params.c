/*
** EPITECH PROJECT, 2019
** concat_params
** File description:
** puts a string into upper cases
*/

#include <stdlib.h>
#include "my.h"

char *my_concat_params(int argc, char **argv)
{
    char *result;
    int total_length;
    int index = 0;

    for (int i = 0; i < argc; i++) {
        for (int j = 0; j < my_strlen(argv[i]); j++) {
            total_length++;
        }
    }
    result = malloc(sizeof(char) * (1 + total_length));
    for (int i = 0; i < argc; i++) {
        for (int j = 0; j < my_strlen(argv[i]); j++) {
            result[index] = argv[i][j];
            index++;
        }
        result[index] = '\n';
        index++;
    }
    result[index] = '\0';
    return result;
}