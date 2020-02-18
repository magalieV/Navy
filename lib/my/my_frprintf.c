/*
** EPITECH PROJECT, 2018
** my_frprintf
** File description:
** it's a rprintf but it free the man char afterward
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include <stddef.h>
#include "my.h"

char *my_frprintf(char *src, ...)
{
    int nb = find_tag(src);
    char **array = malloc(sizeof(char *) * (nb + 1));
    char *str = my_xmalloc(my_strlen(src) + 1);
    int idx = 0;
    va_list ap;

    va_start(ap, src);
    array[nb] = NULL;
    nb = 0;
    for (int index = 0 ; src[index] ; index++) {
        str[idx++] = src[index];
        if (src[index] == '%')
            array[nb++] = engage_function(src, &ap, &index);
    }
    va_end(ap);
    str = get_advenced_str(array, str);
    free(src);
    return (str);
}
