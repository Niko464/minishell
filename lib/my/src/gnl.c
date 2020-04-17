/*
** EPITECH PROJECT, 2019
** gnl.c
** File description:
** this is my gnl
*/

#include "my.h"
#include <unistd.h>
#include <stdlib.h>

char *make_str_bigger(char *str)
{
    char *result = malloc((my_strlen(str) + 2) * sizeof(char));
    int index = 0;

    while (str[index] != '\0') {
        result[index] = str[index];
        index++;
    }
    result[index + 1] = '\0';
    free(str);
    return (result);
}

char *get_next_line(const int fd)
{
    static char buf[READ_SIZE];
    char *line = malloc(sizeof(char));
    int index = 0;
    int read_size = read(fd, buf, READ_SIZE);

    line[0] = '\0';
    while (read_size> 0 && buf[0] != '\n') {
        line = make_str_bigger(line);
        line[index] = buf[0];
        read_size = read(fd, buf, READ_SIZE);
        index++;
    }
    if (read_size == 0 && index == 0)
        return (NULL);
    else
        return (line);
}