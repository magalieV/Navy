/*
** EPITECH PROJECT, 2019
** syncom
** File description:
** syncronisation betten the two terminal
*/

#include "navi.h"

static int const (*pf)(char *, ...) = &my_printf;

extern int flux;

static void in_pid(int i, siginfo_t *info, void *foo)
{
    flux = info->si_pid;
}

static void quiper(int foo)
{
    return;
}

int get_pid_user(void)
{
    struct sigaction tmp;
    int pid;

    pf("my_pid: %d\nwaiting for enemy connection...\n", getpid());
    tmp.sa_sigaction = in_pid;
    sigemptyset(&tmp.sa_mask);
    tmp.sa_restorer = NULL;
    tmp.sa_flags = SA_SIGINFO;
    if (sigaction(SIGUSR1, &tmp, NULL) == -1)
        return (-1);
    pause();
    pid = flux;
    flux = 0;
    return (pid);
}

int wait_answer(void)
{
    struct sigaction tmp;

    tmp.sa_handler = quiper;
    sigemptyset(&tmp.sa_mask);
    tmp.sa_restorer = NULL;
    tmp.sa_flags = SA_NOCLDSTOP;
    if (sigaction(SIGUSR2, &tmp, NULL) == -1)
        return (84);
    pause();
    return (0);
}

int answer(int pid)
{
    usleep(S_TIME);
    if (kill(pid, SIGUSR2) == -1)
        return (84);
    return (0);
}
