/*
** EPITECH PROJECT, 2018
** my_show_word_array.c
** File description:
** display the contene of an array of words
*/

#include <stdlib.h>

int my_show_word_array(char * const *tab);
int my_putstr(char const *str);
void my_putchar(char c);

int my_show_word_array(char * const *tab)
{
    if (tab != NULL) {
        for (int i = 0 ; tab[i] ; i++) {
            my_putstr(tab[i]);
            my_putchar('\n');
        }
    }
    return (0);
}
