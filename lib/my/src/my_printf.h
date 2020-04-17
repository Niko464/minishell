/*
** EPITECH PROJECT, 2019
** my_printf.c
** File description:
** this is where the main functions for my_printf will be
*/

#include <stdarg.h>

#ifndef PRINTF_H
#define PRINTF_H
#include "my.h"

char *add_zeros_to_char(char *str, int nb_zeros);
void my_put_str_with_octal_form(char *str);
void my_print_octal(int to_change, int new_base);
int main_function_printf(va_list list, char c);
int my_printf_hashtag(va_list list, char c);
int get_case_printf(va_list list, char *copy, char c, int i);
int my_printf(char const *format, ...);
void my_put_nbr_base(unsigned long long int to_change, char *base);
void my_put_unsigned_int(unsigned int nb);
void hashtag_octal(unsigned long long int nbr);
void hastag_hexa_min(unsigned long long int nbr);
void hashtag_hexa_maj(unsigned long long int nbr);
int get_index_char(char *str, char c, int occurence);
int count_nbr_percentages(char *str);
char *get_base_for_print(char c);
int my_print_address(unsigned long long int nbr);


#endif