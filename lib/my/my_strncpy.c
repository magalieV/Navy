/*
** EPITECH PROJECT, 2018
** my_strncpy
** File description:
** copy n carateur of a strin to an other
*/

#include <criterion/criterion.h>

char *my_strncpy(char *dest, char const *src, int n);

char *my_strncpy(char *dest, char const *src, int n)
{
    int i;
    int j = 0;

    if (n < 0)
        return (0);
    while (dest[j] != '\0')
        j++;
    for (i = 0 ; i != n ; i++) {
        dest[i] = src[i];
        if (!src[i])
            break;
    }
    if (j < n)
        dest[i] = '\0';
    else
        dest[j + 1] = '\0';
    return (dest);
}
