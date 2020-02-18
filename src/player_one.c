/*
** EPITECH PROJECT, 2019
** PSU_navy_2018
** File description:
** __DESCRIPTION__
*/

#include "navi.h"

static int const (*ps)(char *) = &my_putstr;
static int const (*pf)(char *, ...) = &my_printf;
static char * const (*rf)(char *, ...) = &my_rprintf;
static char * const (*fr)(char *, ...) = &my_frprintf;

int flux = 0;

int end_game(int pid, char **map[2], int w_value[2])
{
    if (w_value[1] == 14) {
        display_map(map);
        ps("Enemy won\n");
        flux = 1;
        return (1);
    }
    return (0);
}

int player_b(int pid, char *path, char **map[2])
{
    int	w_value[2] = {0, 0};

    if (pid <= 0 || craft_map(path, map))
        return (84);
    pf("my_pid: %d\n", getpid());
    usleep(S_TIME);
    if (kill(pid, SIGUSR1) == -1)
        return (84);
    ps("successfully connected\n\n");
    while (!win(pid, map, w_value)) {
        display_map(map);
        if (do_turn(pid, map, w_value, 0))
            return (0);
        if (end_game(pid, map, w_value))
            break;
        if (play_turn(pid, map, w_value, 1))
            return (0);
    }
    return (flux);
}

int player_a(char *path, char **map[2])
{
    int pid;
    int w_value[2] = {0, 0};

    if (craft_map(path, map))
        return (84);
    pid = get_pid_user();
    if (pid <= 0)
        return (84);
    ps("\nenemy connected\n\n");
    usleep(S_TIME);
    while (!end_game(pid, map, w_value)) {
        display_map(map);
        if (play_turn(pid, map, w_value, 0))
            return (0);
        if (win(pid, map, w_value))
            break;
        if (do_turn(pid, map, w_value, 1))
            return (0);
    }
    return (flux);
}
