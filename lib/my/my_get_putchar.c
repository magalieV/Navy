/*
** EPITECH PROJECT, 2018
** my_get_putchar
** File description:
** convert a char into a str
*/

#include <stdlib.h>

char *my_get_putchar(char c)
{
    char *str = malloc(sizeof(char) * 2);

    str[0] = c;
    str[1] = 0;
    return (str);
}
