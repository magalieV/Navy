/*
** EPITECH PROJECT, 2019
** player_a.c
** File description:
** first player doing
*/

#include "navi.h"

static int const (*ps)(char *) = &my_putstr;
static int const (*pf)(char *, ...) = &my_printf;
static char * const (*rf)(char *, ...) = &my_rprintf;
static char * const (*fr)(char *, ...) = &my_frprintf;

extern int flux;

int hit_or_miss_igtnm(int pid, int attack, char *line, char **map[2])
{
    send_msg(pid, attack);
    get_msg(pid);
    if (flux) {
        pf("%s: hit\n", line);
        map[1][(attack & 7) + 2][2 + (attack >> 3) * 2] = 'x';
        return (1);
    }
    pf("%s: missed\n", line);
    map[1][(attack & 7) + 2][2 + (attack >> 3) * 2] = 'o';
    return (0);
}

int play_turn(int pid, char **map[2], int w_value[2], int n)
{
    char *tmp;
    char *line = rf("");
    int attack = -1;

    while (attack == -1) {
        ps("attack: ");
        tmp = get_next_line(0);
        if (!tmp)
            return (send_msg(pid, 64) + 1);
        line = rf("%0!%!", line, tmp);
        if (my_strlen(line) == 2 && line[0] > 64 && line[0] < 73
            && line[1] > 48 && line[1] < 57)
            attack = ((line[0] - 65) << 3) + line[1] - 49;
        else
            ps("wrong position\n");
    }
    w_value[0] += hit_or_miss_igtnm(pid, attack, line, map);
    if (n)
        write(1, "\n", 1);
    return (free(line), 0);
}

int do_turn(int pid, char **map[2], int w_value[2], int n)
{
    char cell;

    if (n)
        write(1, "\n", 1);
    ps("waiting for enemy's attack...\n");
    get_msg(pid);
    if (flux == 64)
        return (1);
    cell = map[0][(flux & 7) + 2][2 + (flux >> 3) * 2];
    if (cell > 49 && cell < 54) {
        pf("%c%d: hit\n\n", (flux >> 3) + 65, (flux & 7) + 1, w_value[1]++);
        map[0][(flux & 7) + 2][2 + (flux >> 3) * 2] = 'x';
        send_msg(pid, 1);
    } else {
        pf("%c%d: missed\n\n", (flux >> 3) + 65, (flux & 7) + 1);
        if (cell != 'x')
            map[0][(flux & 7) + 2][2 + (flux >> 3) * 2] = 'o';
        send_msg(pid, 0);
    }
    return (0);
}

int win(int pid, char **map[2], int w_value[2])
{
    if (w_value[0] == 14) {
        display_map(map);
        ps("I won\n");
        flux = 0;
        return (1);
    }
    return (0);
}
