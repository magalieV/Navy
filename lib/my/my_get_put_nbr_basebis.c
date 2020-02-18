/*
** EPITECH PROJECT, 2018
** my_put_nbr.c
** File description:
** display a number
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"

char *my_get_put_base_hexa_void(unsigned long nbr)
{
    char base[] = "0123456789abcdef";
    char *str = NULL;
    int b = 16;

    str = char_append(str, '0');
    str = char_append(str, 'x');
    str = get_positive_number_base(nbr, b, base, str);
    return (str);
}

char *my_get_put_base_binaire(unsigned int nbr)
{
    char base[] = "01";
    char *str = NULL;
    int b = 2;

    str = get_positive_number_base(nbr, b, base, str);
    return (str);
}

char *my_get_put_nbr(int nb)
{
    char base[] = "0123456789";
    char *str = NULL;
    long nbr = nb;
    int b = 10;

    if (nb < 0) {
        nbr = -nbr;
        str = char_append(str, '-');
    }
    str = get_positive_number_base(nbr, b, base, str);
    return (str);
}
