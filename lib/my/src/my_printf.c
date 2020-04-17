/*
** EPITECH PROJECT, 2019
** my_printf.c
** File description:
** this is where the main functions for my_printf will be
*/

#include <stdlib.h>
#include "my_printf.h"
#include "my.h"

void (*ptr_func[10])() = {my_putstr, my_put_str_with_octal_form,
    my_putchar, my_put_nbr, my_put_nbr, my_put_unsigned_int};

void (*ptr_func_hashtag[3])() = {hashtag_octal, hastag_hexa_min,
    hashtag_hexa_maj};

const char flags[] = "sScdiu";
const char flags_multi_params[] = "obxX";
const char flags_hashtag[] = "oxX";

int main_function_printf(va_list list, char c)
{
    for (int j = 0; j < my_strlen(flags); j++) {
        if (flags[j] == c) {
            ptr_func[j](va_arg(list, void *));
            return (0);
        }
    }
    for (int j = 0; j < my_strlen(flags_multi_params); j++) {
        if (flags_multi_params[j] == c) {
            my_put_nbr_base(va_arg(list, unsigned long long int),
            get_base_for_print(c));
            return (0);
        }
    }
    if (c == 'p') {
        return (my_print_address(va_arg(list, unsigned long long int)));
    }
    my_putchar('%');
    if (c != '%')
        my_putchar(c);
    return (0);
}

int my_printf_hashtag(va_list list, char c)
{
    for (int j = 0; j < my_strlen(flags_hashtag); j++) {
        if (flags_hashtag[j] == c) {
            ptr_func_hashtag[j](va_arg(list, unsigned long long int));
            return (0);
        }
    }
    return (0);
}

int get_case_printf(va_list list, char *copy, char c, int i)
{
    if (c == '#') {
        my_printf_hashtag(list, copy[i + 2]);
        return (2);
    } else {
        main_function_printf(list, copy[i + 1]);
        return (1);
    }
    return (0);
}

int my_printf(char const *format, ...)
{
    char *copy = malloc(sizeof(char) * (my_strlen(format) + 1));
    my_strcpy(copy, format);
    va_list list;
    va_start(list, format);
    for (int i = 0; i < my_strlen(copy); i++) {
        if (copy[i] != '%')
            my_putchar(copy[i]);
        else {
            i += get_case_printf(list, copy, copy[i + 1], i);
        }
    }
    va_end(list);
    free(copy);
    return (0);
}