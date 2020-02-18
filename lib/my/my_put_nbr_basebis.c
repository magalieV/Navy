/*
** EPITECH PROJECT, 2018
** my_put_nbr.c
** File description:
** display a number
*/

#include <unistd.h>
#include "my.h"

int my_put_base_hexa_void(unsigned long nbr)
{
    char base[] = "0123456789abcdef";
    int b = 16;

    write(1, "0x", 2);
    print_positive_number_base(nbr, b, base);
    return (0);
}
