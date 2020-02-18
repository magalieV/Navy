/*
** EPITECH PROJECT, 2018
** my_get_to_line
** File description:
** go to line
*/

#include "my.h"
#include <stdlib.h>

char *my_get_to_line(int nb)
{
    return (my_rprintf("%s%d%s", "\e[", nb, "d"));
}
