/*
** EPITECH PROJECT, 2018
** number
** File description:
** get a number in a str as a str
*/

#include "my.h"
#include <stddef.h>

char *number(char *src, int *idx)
{
    char *nb = NULL;

    for (*idx = *idx ; 47 < src[*idx] && src[*idx] < 58 ; (*idx)++)
        nb = char_append(nb, src[*idx]);
    return (nb);
}
