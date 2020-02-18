/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** generique main by a script of my own
*/

#include "navi.h"

static int const (*ps)(char *) = &my_putstr;
static int const (*pf)(char *, ...) = &my_printf;
static char * const (*rf)(char *, ...) = &my_rprintf;
static int const (*fp)(char *, ...) = &my_fprintf;
static char * const (*fr)(char *, ...) = &my_frprintf;

int display_help(void)
{
    ps("USAGE\n");
    ps("\t./navy [first_player_pid] navy_positions\n");
    ps("DESCRIPTION\n");
    ps("\tfirst_player_pid:  only for the 2nd player.");
    ps("  pid of the first player.\n");
    ps("\tnavy_positions:  file representing the positions of the ships.\n");
    return (0);
}

int main(int argc, char **argv)
{
    char **map[2] = {NULL, NULL};
    struct sigaction tmp;
    int e_xit = 0;

    if (argc == 2 && eq_str(argv[1], "-h"))
        display_help();
    if (argc == 2)
        e_xit = player_a(argv[1], map);
    else if (argc == 3)
        e_xit = player_b(my_getnbr(argv[1]), argv[2], map);
    else
        return (84);
    destroy_map(map);
    return (e_xit);
}
