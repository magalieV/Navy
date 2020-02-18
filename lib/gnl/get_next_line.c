/*
** EPITECH PROJECT, 2018
** get_next_line.c
** File description:
** get the next line of a file or the standard input
*/

#include "get_next_line.h"

int error_malloc(char **src, int nb, int *error)
{
    char *str = malloc(sizeof(char) * nb);

    if (*error == 84 || !str)
        *error = 84;
    if (*error == -52) {
        *error = 84;
        *src = str;
        return (0);
    }
    *src = str;
    return (*error);
}

char *get_next_line(int fd)
{
    static char *over_flow = NULL;
    int size = 1;
    char buffer[READ_SIZE];
    char *str = NULL;
    int err = 0;

    if (fd < 0)
        return (NULL);
    if (over_flow)
        str = output_overflow(&over_flow, &err);
    while (!str && size) {
        size = read(fd, buffer, READ_SIZE);
        if (size == -1 || input_overflow(&over_flow, buffer, size, &err) == 84)
            return (NULL);
        if (over_flow && size)
            str = output_overflow(&over_flow, &err);
    }
    return ((str) ? str :  output_lastline(&over_flow, &err));
}

int input_overflow(
    char **over_flow,
    char buffer[READ_SIZE],
    int len,
    int *error)
{
    int t_len = -1;
    char *new;

    if (!len)
        return (1);
    else if (*over_flow)
        while ((*over_flow)[++t_len]);
    else
        t_len = 0;
    if (error_malloc(&new, len + t_len + 1, error) == 84)
        return (*error);
    for (int cmn = 0 ; cmn != t_len ; cmn++)
        new[cmn] = (*over_flow)[cmn];
    for (int cmn = 0 ; cmn != len ; cmn++)
        new[cmn + t_len] = buffer[cmn];
    new[len + t_len] = 0;
    if (*over_flow)
        free(*over_flow);
    *over_flow = new;
    return (0);
}

char *output_overflow(char **fl, int *error)
{
    char *start;
    char *end;
    int len[2] = {-1, -1};

    while ((*fl)[++len[0]]);
    while ((*fl)[++len[1]] && (*fl)[len[1]] != '\n');
    if ((*fl)[len[1]] != '\n' || error_malloc(&start, len[1] + 1, error) == 84)
        return (NULL);
    for (int i = 0 ; i != len[1] ; start[i - 1] = (*fl)[i++]);
    start[len[1]] = 0;
    if (len[0] - len[1] <= 1)
        end = NULL;
    else {
        if (error_malloc(&end, len[0] - len[1], error) == 84)
            return (NULL);
        for (int i = len[1] + 1; i <= len[0]; end[i - len[1] - 2] = (*fl)[i++]);
    }
    free(*fl);
    *fl = end;
    return (start);
}

char *output_lastline(char **over_flow, int *error)
{
    char *start;
    int t_len = -1;

    if (*over_flow == NULL)
        return (NULL);
    while ((*over_flow)[++t_len]);
    if (error_malloc(&start, t_len + 1, error) == 84)
        return (NULL);
    for (int cmn = 0 ; cmn != t_len ; cmn++)
        start[cmn] = (*over_flow)[cmn];
    start[t_len] = 0;
    free(*over_flow);
    *over_flow = NULL;
    return (start);
}
