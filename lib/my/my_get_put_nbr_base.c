/*
** EPITECH PROJECT, 2018
** my_put_nbr.c
** File description:
** display a number
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"

char *get_positive_number_base(unsigned long nb, int b, char *base, char *str)
{
    if (nb > b - 1)
        str = get_positive_number_base(nb / b, b, base, str);
    str = char_append(str, base[nb % b]);
    return (str);
}

char *my_get_put_base_hexa_cap(unsigned int nb)
{
    char base[] = "0123456789ABCDEF";
    char *str = NULL;
    int b = 16;

    str = get_positive_number_base(nb, b, base, str);
    return (str);
}

char *my_get_put_base_hexa_min(unsigned int nb)
{
    char base[] = "0123456789abcdef";
    char *str = NULL;
    int b = 16;

    str = get_positive_number_base(nb, b, base, str);
    return (str);
}

char *my_get_put_base_octal(unsigned int nb)
{
    char base[] = "01234567";
    char *str = NULL;
    int b = 8;

    str = get_positive_number_base(nb, b, base, str);
    return (str);
}

char *my_get_put_unsignednbr(unsigned int nb)
{
    char base[] = "0123456789";
    char *str = NULL;
    int b = 10;

    str = get_positive_number_base(nb, b, base, str);
    return (str);
}
