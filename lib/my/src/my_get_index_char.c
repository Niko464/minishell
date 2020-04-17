/*
** EPITECH PROJECT, 2019
** get_index_char.c
** File description:
** gets the index of a char in a str
*/

int my_get_index_char(char *str, char c, int which_one)
{
    int index = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == c)
            index++;
        if (which_one == index)
            return (i);
    }
    return (-1);
}