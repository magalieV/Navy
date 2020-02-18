/*
** EPITECH PROJECT, 2018
** my_getnbr.c
** File description:
** return an int from a str
*/

#include "my.h"

int getnb(char const *src)
{
    int len = my_strlen(src);
    char c = *src;
    int nb = 0;

    if (c != 45) {
        if (len > 10)
            return (0);
        if (len == 10 && my_strcmp(src, "2147483647") > 0)
            return (0);
    }
    if (c == 45) {
        if (len > 11)
            return (0);
        if (len == 11 && my_strcmp(src, "-2147483648") > 0)
            return (0);
    }
    src = (c == 45) ? &src[1] : src;
    for (int i = 0 ; src[i] ; i++)
        nb = nb * 10 + src[i] - 48;
    return ((c == 45) ? (-nb) : (nb));
}

int my_getnbr(char const *str)
{
    int i;
    int nb = 0;
    int neg = 1;

    for (i = 0 ; *(str + i) == 45 || *(str + i) == 43 ; i++)
        if (*(str + i) == 45)
            neg = -neg;
    if (*(str + i) > 57 || *(str + i) < 48)
        return (0);
    for (i = i ; *(str + i) < 58 && *(str + i) > 47 ; i++) {
        if (nb == 214748364 && *(str + i) == -(8 + 48) * neg
            && !(str[i + 1] < 58 && str[i + 1] > 47))
            return (-2147483648);
        if ((nb == 214748364 && *(str + i) > 7 + 48) || nb > 214748364)
            return (0);
        nb = nb * 10 + (*(str + i) - 48);
    }
    return (nb * neg);
}
