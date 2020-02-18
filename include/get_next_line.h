/*
** EPITECH PROJECT, 2018
** get_next_line.h
** File description:
** prototype for get_next_line
*/

#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

#ifndef READ_SIZE
#   define READ_SIZE (52)
#endif /* !READ_SIZE */

#ifndef GET_NEXT_LINE_H_
#define GET_NEXT_LINE_H_

char *get_next_line(int fd);
char *output_overflow(char **fl, int *error);
char *output_lastline(char **over_flow, int *error);
int error_malloc(char **src, int nb, int *error);
int input_overflow(
    char **over_flow,
    char buffer[READ_SIZE],
    int len,
    int *error);

#endif
