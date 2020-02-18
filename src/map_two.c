/*
** EPITECH PROJECT, 2019
** PSU_navy_2018
** File description:
** __MAP TWO__
*/

#include "navi.h"

static int const (*pf)(char *, ...) = &my_printf;

int craft_map_navy_two(char uff[8], char **map[2])
{
    for (int i = 0 ; uff[2] + i <= uff[5] ; i++) {
        if (map[0][uff[3] - 47][(uff[2] - 64 + i) * 2] != '.')
            return (84);
        map[0][uff[3] - 47][(uff[2] - 64 + i) * 2] = uff[0];
    }
    return (0);
}

int craft_map_navy_one(char uff[8], char **map[2])
{
    for (int i = 0 ; uff[3] + i <= uff[6] ; i++) {
        if (map[0][uff[3] - 47 + i][(uff[2] - 64) * 2] != '.')
            return (84);
        map[0][uff[3] - 47 + i][(uff[2] - 64) * 2] = uff[0];
    }
    return (0);
}

int craft_navy(char **map[2], char *uff)
{
    int lett[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 0};

    if (!eq_int_in_array(uff[2], lett, 0) || !eq_int_in_array(uff[5], lett, 0))
        return (84);
    if (uff[0] < '2' || uff[0] > '5' || uff[1] != ':' || uff[4] != ':'
        || size_chip(map, uff[0]))
        return (84);
    if (!((uff[2] != uff[5]) ^ (uff[3] != uff[6]) &&
        (uff[5] - uff[2] + uff[6] - uff[3]) == uff[0] - 49))
        return (84);
    if (uff[3] != uff[6]) {
        if (craft_map_navy_one(uff, map))
            return (84);
    } else if (craft_map_navy_two(uff, map))
            return (84);
    return (0);
}

int craft_map(char *path, char **map[2])
{
    int fd[2] = {open(path, O_RDONLY), 0};
    char *line;

    if (fd[0] == -1)
        return (84);
    fd[1] = open("map/map_src", O_RDONLY);
    map[0] = malloc(sizeof(char *) * 10);
    map[1] = malloc(sizeof(char *) * 10);
    for (int i = 0 ; i < 10 ; i++) {
        map[0][i] = get_next_line(fd[1]);
        map[1][i] = my_strdup(map[0][i]);
    }
    for (int i = 0 ; i != 4 ; i++) {
        line = get_next_line(fd[0]);
        if (!line || my_strlen(line) != 7 || craft_navy(map, line))
            return (close(fd[0]), close(fd[1]), 84);
    }
    line = get_next_line(fd[0]);
    if (line)
        return (close(fd[0]), close(fd[1]), 84);
    return (close(fd[0]), close(fd[1]), 0);
}
