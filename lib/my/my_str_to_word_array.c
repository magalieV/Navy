/*
** EPITECH PROJECT, 2018
** my_str_to_word_array.c
** File description:
** convert a str into a arrays
*/

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

int is_alfanum(char c);
int nb_word(char const *str);
char **my_str_to_word_array(char const *str);
int my_show_word_array(char * const *tab);
void adding_to_my_str(char *my_str, char const *str, int i, int j);

char **my_str_to_word_array(char const *str)
{
    int nb = nb_word(str);
    int in_word_nb = 0;
    int y = 0;
    char **arrays = malloc(sizeof(char *) * (nb + 1));
    char *my_str;

    arrays[nb] = NULL;
    for (int i = 0 ; str[i] ; i++) {
        for (y = i ; is_alfanum(str[y]) ; y++)
            continue;
        if (y > i)
            my_str = malloc(sizeof(char) * (y - i + 1));
        for (int j = i ; j < y ; j++)
            adding_to_my_str(my_str, str, i, j);
        if (y > i) {
            i = y - 1;
            arrays[in_word_nb++] = my_str;
        }
    }
    return (arrays);
}

int is_alfanum(char c)
{
    if (c > 47 && c < 58)
        return (1);
    if (c > 64 && c < 91)
        return (1);
    if (c > 96 && c < 123)
        return (1);
    return (0);
}

int nb_word(char const *str)
{
    int o_bool = 0;
    int y = 0;

    if (str == NULL)
        return (0);
    for (int i = 0 ; str[i] ; i++) {
        if (is_alfanum(str[i]) && !o_bool) {
            o_bool = 1;
            y++;
        } else if (!is_alfanum(str[i])) {
            o_bool = 0;
        }
    }
    return (y);
}

void adding_to_my_str(char *my_str, char const *str, int i, int j)
{
    my_str[j - i] = str[j];
    my_str[j - i + 1] = '\0';
}
