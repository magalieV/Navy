/*
** EPITECH PROJECT, 2018
** my_putstr.c
** File description:
** Display all caracters of a string
*/

#include <unistd.h>

void my_putchar(char c);
int my_putstr(char const *str);

int my_putstr(char const *str)
{
    int i = 0;
    while (*(str + i) != '\0') {
        my_putchar(*(str + i));
        i++;
    }
    return (0);
}
