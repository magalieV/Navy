/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** include all
*/

#ifndef MY_H_
#define MY_H_

int print_positive_number(int nb);
int print_positive_number_base(unsigned int nb, int b, char *base);
int my_put_base_hexa_cap(unsigned int nb);
int my_put_base_hexa_min(unsigned int nb);
int my_put_base_octal(unsigned int nb);
int my_put_unsignednbr(unsigned int nb);
void my_swap(int *a, int *b);
void my_putchar(char c);
int my_putstr(char *str);
int my_strlen(char const *str);
int getnb(char const *src);
int my_getnbr(char const *str);
void my_sort_int_array(int *tab, int size);
int my_sort_strlen(int *array);
void swap_that_int(int *array, int y);
int my_compute_power_rec(int nb, int power);
int my_compute_square_root(int nb);
int divisional_tracking(int const nb, int min, int max);
int my_is_prime(int nb);
int my_find_prime_sup(int nb);
int is_it_prime(int nb);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_revstr(char *str);
int my_evil_strlen(char *str);
char *my_strstr(char *str, char const *to_find);
int check_if(char *str, char const *to_find, int i);
int my_str_len(char *str);
int eq_str(char const *s1, char const *s2);
int my_strcmp(char const *s1, char const *s2);
int my_strfcmp(char const *s1, char const *s2);
int which(char const *s1, char const *s2, int i);
int my_strncmp(char const *s1, char const *s2, int n);
int s1_len(char const *s1);
int s2_len(char const *s2);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcapitalize(char *str);
char modif_str(char *str, int i);
int my_str_isalpha(char const *str);
int my_str_isnum(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isprintable(char const *str);
int my_str_isinlexicode(char const *src, char const *lexicode);
int my_showstr(char const *str);
int my_showmem(char *dest, char const *src);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int nb);
int my_show_word_array(char * const *tab);
char **my_str_to_word_array(char const *str);
int is_alfanum(char c);
int nb_word(char const *str);
void adding_to_my_str(char *my_str, char const *str, int i, int j);
char *number(char *src, int *idx);
char *my_strdup(char const *src);
char *my_strdupmax(char const *src, int max);

int my_put_nbr(int nb);
int len_number(int nb, int nb_len);
int my_pow(int nb, int expo);
int check_min(int nb);
void my_putchar(char c);
int my_put_nbr(int nb);

#include <stdarg.h>
int my_printf(char *str, ...);
int display_advenced_str(char **array, char *str);
char *engage_function(char *src, va_list *ap, int *idx);
char *number_merge(char *src, char *nb, char akaa);
int find_tag(char *str);

char *my_rprintf(char *src, ...);
char *get_advenced_str(char **array, char *src);
char *get_array_in_str(char *str, char *src, int *len);

int my_fprintf(char *src, ...);
char *my_frprintf(char *src, ...);

char *my_xmalloc(int i);
char *char_append(char *str, char c);
char *char_nappend(char *str, char *src);
char *char_len_append(char *str, char c, int *len);

char *get_positive_number(int nb, char *str);
char *get_positive_number_base(unsigned long nb, int b, char *base, char *str);

char *my_get_putchar(int c);
char *my_get_stroctal(char *str);
char *my_get_put_nbr(int i);
char *my_get_put_base_hexa_cap(unsigned int nb);
char *my_get_put_base_hexa_min(unsigned int nb);
char *my_get_put_base_hexa_void(unsigned long nb);
char *my_get_put_base_octal(unsigned int nb);
char *my_get_put_base_binaire(unsigned int nb);
char *my_get_put_unsignednbr(unsigned int nb);
char *my_get_put_color(char *src);
char *my_get_put_emoji(char *src);
char *my_get_to_line(int nb);
char *my_get_putstrmax(char *src, int max);

char *my_returnstr(char *src);

char *display_help_emoji(void);
char *display_help_color(void);

struct printf_func
{
    int func;
    char *(*displayfunc)();
};

struct color_s
{
    char *name;
    char *core;
};

#endif
