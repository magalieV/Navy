/*
** EPITECH PROJECT, 2018
** my_getstroctal.c
** File description:
** Display all caracters of a string
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"

char *add_null_to_octal(char *str, char *octal, char c)
{
    if (c < 8) {
        str = char_append(str, '0');
        str = char_append(str, '0');
    } else if (c < 64)
        str = char_append(str, '0');
    for (int i = 0 ; octal[i] ; i++)
        str = char_append(str, octal[i]);
    return (str);
}

char *my_get_stroctal(char *src)
{
    char *str = NULL;
    char *octal = NULL;
    int i;

    for (i = 0 ; src[i] != '\0' ; i++)
        if (31 < src[i] && src[i] < 127)
            str = char_append(str, src[i]);
        else {
            str = char_append(str, '\\');
            octal = my_get_put_base_octal(src[i]);
            str = add_null_to_octal(str, octal, src[i]);
            free(octal);
            octal = NULL;
        }
    return (str);
}
