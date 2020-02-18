/*
** EPITECH PROJECT, 2018
** malloc_char_append.c
** File description:
** add a char in a str to the end of a list
*/

#include <stddef.h>
#include <stdlib.h>
#include "my.h"

char *my_xmalloc(int i)
{
    char *str = malloc(i + 1);

    for (int commoner = 0 ; commoner != i ; commoner++)
        str[commoner] = 0;
    str[i] = 0;
    return (str);
}

char *char_nappend(char *str, char *src)
{
    char *new_str;
    int i;
    int j;

    if (str == NULL) {
        new_str = malloc(sizeof(char) * (my_strlen(src) + 1));
        for (i = 0 ; src[i] ; i++)
            new_str[i] = src[i];
        new_str[i] = 0;
    } else {
        new_str = malloc(sizeof(char) * (my_strlen(str) + my_strlen(src) + 1));
        for (i = 0 ; str[i] ; i++)
            new_str[i] = str[i];
        for (j = 0 ; src[j] ; j++)
            new_str[i + j] = src[j];
        new_str[i + j + 1] = 0;
        free(str);
    }
    return (new_str);
}

char *char_append(char *str, char c)
{
    char *new_str;
    int i;

    if (str == NULL) {
        new_str = malloc(sizeof(char) * 2);
        new_str[0] = c;
        new_str[1] = '\0';
    } else {
        new_str = malloc(sizeof(char) * (my_strlen(str) + 2));
        for (i = 0 ; str[i] ; i++)
            new_str[i] = str[i];
        new_str[i] = c;
        new_str[i + 1] = '\0';
        free(str);
    }
    return (new_str);
}

char *char_len_append(char *str, char c, int *len)
{
    char *new_str;
    int i;

    if (str == NULL) {
        new_str = malloc(sizeof(char) * 2);
        new_str[0] = c;
        new_str[1] = '\0';
    } else {
        new_str = malloc(sizeof(char) * (*len + 2));
        for (i = 0 ; i != *len ; i++)
            new_str[i] = str[i];
        new_str[i] = c;
        new_str[i + 1] = '\0';
        free(str);
    }
    (*len)++;
    return (new_str);
}
