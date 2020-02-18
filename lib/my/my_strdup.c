/*
** EPITECH PROJECT, 2018
** my_strdup
** File description:
** allocates memory and copies the string given as argument
*/

#include <stdlib.h>

char *my_strdup(char const *src);
int my_strlen(char const *str);

char *my_strdup(char const *src)
{
    int len = my_strlen(src);
    char *str = malloc(sizeof(char) * (len + 1));

    for (int i = 0 ; i != len ; i++)
        str[i] = src[i];
    str[len] = 0;
    return (str);
}
