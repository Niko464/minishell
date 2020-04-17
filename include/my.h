/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** Header for the library 'my'
*/

#ifndef MY_H
#define MY_H

#define READ_SIZE (1)
typedef struct gnl {
    int curr_size;
    int n1;
} gnl_t;


void my_putchar(char c);
int my_put_nbr(int nb);
void my_swap(int *a, int *b);
void my_perror(char *str);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
void my_sort_int_array(int *tab, int size);
int my_compute_power_rec(int nb, int power);
int my_compute_square_root(int nb);
int my_is_prime(int nb);
int my_find_prime_sup(int nb);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_revstr(char *str);
char *my_strstr(char *str, char const *to_find);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcapitalize(char *str);
int my_str_isalpha(char const *str);
int my_str_isnum(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isprintable(char const *str);
int my_showstr(char const *str);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int nb);
int my_show_word_array(char * const *tab);
char **my_str_to_word_array(char const *str);
char *concat_params(int argc, char **argv);
char *my_strdup(char const *src);
char *my_check_string_is_number(char const *str);
int my_str_to_int(char *str);
int my_get_nbr_operators(char const *str);
int *my_sort(int *tab, int longueur);
char my_get_sign(char const *str);
char *my_int_to_str(int nb);
int my_intlen(int nb);
char *my_cut_string(char const *str, int start, int end);
void my_putfloat(float my_float, int nbr);
void my_putlong(long my_long);
int my_get_index_char(char *str, char c, int which_one);
int my_count_char(char const *str, char c);
char *my_buffer(char *filepath, int size, int end_char);
int matching_letter(int i, char *str, char const *to_find);
int count_separators(char const *str);
int check_ifnul_or_alpha(char c, int i, int length);
int alphanumerical(char c);
int is_not_banned_char(char c);
int spec_is_separator(char *str, int len_str, int i,
    int *found_letter);
int spec_count_separators(char *str);
char *my_remove_spaces(char *str);
int my_binary_to_int(char *binary);
char *concat_slash(char *s1, char *s2);
char *mem_set(int len);
char *get_next_line(int fd);
char *my_glue_cut_str(char *str1, char *str2, int start_str_2, int end_str2);
int my_str_aplha_or_int(char *str);
int my_char_is_alpha(char c);
int my_char_is_int(char c);

#endif