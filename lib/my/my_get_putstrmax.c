/*
** EPITECH PROJECT, 2018
** my_strdupmax
** File description:
** allocates memory and copies the string given as argument
*/

#include <stdlib.h>
#include "my.h"

char *my_strdupmax(char const *src, int max)
{
    char *str;
    int len = my_strlen(src);

    max = (max > len) ? (len) : (max);
    str = malloc(sizeof(char) * (max + 1));
    for (int i = 0 ; i != max ; i++)
        str[i] = src[i];
    str[max] = 0;
    return (str);
}

char *my_get_putstrmax(char *src, int max)
{
    char *str;
    int len = my_strlen(src);

    max = (max > len) ? (len) : (max);
    str = malloc(sizeof(char) * (max + 1));
    for (int i = 0 ; i != max ; i++)
        str[i] = src[i];
    str[max] = 0;
    free(src);
    return (str);
}
