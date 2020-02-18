/*
** EPITECH PROJECT, 2018
** my_put_nbr.c
** File description:
** display a number
*/

#include <unistd.h>

int print_positive_number_base(unsigned long nb, int b, char *base)
{
    char c;

    if (nb > b - 1)
        print_positive_number_base(nb / b, b, base);
    c = base[nb % b];
    write(1, &c, 1);
    return (0);
}

int my_put_base_hexa_cap(unsigned int nb)
{
    char base[] = "0123456789ABCDEF";
    int b = 16;

    print_positive_number_base(nb, b, base);
    return (0);
}

int my_put_base_hexa_min(unsigned int nb)
{
    char base[] = "0123456789abcdef";
    int b = 16;

    print_positive_number_base(nb, b, base);
    return (0);
}

int my_put_base_octal(unsigned int nb)
{
    char base[] = "01234567";
    int b = 8;

    print_positive_number_base(nb, b, base);
    return (0);
}

int my_put_unsignednbr(unsigned int nb)
{
    char base[] = "0123456789";
    int b = 10;

    print_positive_number_base(nb, b, base);
    return (0);
}
