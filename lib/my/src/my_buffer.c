/*
** EPITECH PROJECT, 2019
** my_buffer.c
** File description:
** my_buffer function
*/

#include "my.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

char *my_buffer(char *filepath, int size, int end_char)
{
    char *buffer = malloc(sizeof(char) * size + 1);
    int fd = open(filepath, O_RDONLY);
    buffer[size] = '\0';
    read(fd, buffer, size);
    close(fd);
    if (buffer[size - 1] == end_char)
        return (buffer);
    my_buffer(filepath, size + 1, end_char);
}