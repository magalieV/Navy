/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include <stddef.h>
#include "my.h"

char *get_array_in_str(char *str, char *src, int *len)
{
    int new_len = *len + my_strlen(src);
    char *new_str = malloc(sizeof(char) * (new_len + 1));
    int i;
    int j;

    for (i = 0 ; i != *len ; i++)
        new_str[i] = str[i];
    for	(j = 0 ; src[j] ; j++)
        new_str[i + j] = src[j];
    new_str[i + j] = 0;
    *len = new_len;
    free(str);
    return (new_str);
}

char *get_advenced_str(char **array, char *src)
{
    char *str = malloc(1);
    int idx = 0;
    int len = 0;

    *str = 0;
    for (int i = 0 ; src[i] ; i++)
        if (src[i] == '%') {
            str = get_array_in_str(str, array[idx], &len);
            free(array[idx++]);
        } else
            str = char_len_append(str, src[i], &len);
    str = char_len_append(str, 0, &len);
    free(src);
    free(array);
    return (str);
}

char *my_rprintf(char *src, ...)
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
    return (str);
}
