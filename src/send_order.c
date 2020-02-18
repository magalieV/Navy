/*
** EPITECH PROJECT, 2019
** send_order
** File description:
** send an order betten two terminal
*/

#include "navi.h"

static int const (*pf)(char *, ...) = &my_printf;
static int const (*ps)(char *) = &my_putstr;

int send_msg(int pid, int msg)
{
    usleep(S_TIME * 10);
    for (int i = 6 ; i != -1 ; i--) {
        usleep(S_TIME);
        if (kill(pid, ((msg >> i) & 1) ? SIGUSR1 : SIGUSR2) == -1)
            return (84);
    }
    return (0);
}
