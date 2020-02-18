/*
** EPITECH PROJECT, 2019
** get_order.c
** File description:
** get an order from the over player
*/

#include "navi.h"

static int const (*pf)(char *, ...) = &my_printf;
static int const (*ps)(char *) = &my_putstr;

extern int flux;

static void handler(int signum)
{
    if (signum == SIGUSR1) {
        flux = (flux << 1) + 1;
    } else if (signum == SIGUSR2) {
        flux = flux << 1;
    }
}

int get_msg(int pid)
{
    struct sigaction tmp;

    flux = 0;
    tmp.sa_handler = handler;
    sigemptyset(&tmp.sa_mask);
    tmp.sa_flags = SA_RESTART;
    for (int i = 0 ; i != 7 ; i++) {
        if (sigaction(SIGUSR1, &tmp, NULL) == -1)
            return (84);
        if (sigaction(SIGUSR2, &tmp, NULL) == -1)
            return (84);
        pause();
    }
    return (0);
}
