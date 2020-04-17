/*
** EPITECH PROJECT, 2019
** my_strstr
** File description:
** strs function
*/

#include "my.h"

int matching_letter(int i, char *str, char const *to_find)
{
    int index = 0;
    char length = my_strlen(to_find);

    for (int j = 0; j <= length; j++) {
        if ((str[i + j] == to_find[j])) {
            index++;
        }
    }
    if (length == index) {
        return index;
    } else {
        return 0;
    }
}

char *my_strstr(char *str, char const *to_find)
{
    char length = my_strlen(str);
    int result = 0;
    int sauvegarde;

    for (int i = 0; i < length;i++) {
        if (str[i] == to_find[0] && result == 0) {
            result = matching_letter(i, str, to_find);
            sauvegarde = i;
        }
    }
    if (result != 0) {
        for (int i = 0; i < sauvegarde; i++) {
            *str++;
        }
        return str;
    } else {
        return 0;
    }
}