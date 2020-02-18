/*
** EPITECH PROJECT, 2019
** map
** File description:
** function related to the map
*/

#include "navi.h"

static int const (*pf)(char *, ...) = &my_printf;

int display_map(char **map[2])
{
    pf("my positions:\n");
    for (int i = 0 ; i != 10 ; i++)
        pf("%s\n", map[0][i]);
    pf("\nenemy's positions:\n");
    for (int i = 0 ; i != 10 ; i++)
        pf("%s\n", map[1][i]);
    my_putchar('\n');
    return (0);
}

int destroy_map(char **map[2])
{
    if (!map[0] || !map[1])
        return (1);
    for (int i = 0 ; i != 10 ; i++) {
        free(map[0][i]);
        free(map[1][i]);
    }
    free(map[0]);
    free(map[1]);
    return (0);
}

int eq_int_in_array(int idx, int ref[], int end)
{
    for (int i = 0; ref[i] != end; i++)
        if (ref[i] == idx)
            return (1);
    return (0);
}

int size_chip(char **map[2], char ref)
{
    int line = 2;

    for (int i = 2; line != 10; i++) {
        if (map[0][line][i] == ref)
            return (84);
        if (map[0][line][i] == ref + 1)
            return (84);
        if (i == 16) {
            i = 1;
            line++;
        }
    }
    return (0);
}
