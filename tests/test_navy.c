/*
** EPITECH PROJECT, 2018
** test_bsq
** File description:
** unit test for the bsq
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>

#include "navi.h"

static int const (*pf)(char *, ...) = &my_printf;
static char * const (*rf)(char *, ...) = &my_rprintf;
static int const (*fp)(char *, ...) = &my_fprintf;
static char * const (*fr)(char *, ...) = &my_frprintf;

void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

int set_arg(char *file, char **msg)
{
    int fd = open(file, O_RDONLY);
    char *tmp = NULL;

    tmp = get_next_line(fd);
    while (tmp) {
        *msg = rf("%!%!\n", *msg, tmp);
        tmp = get_next_line(fd);
    }
    close(fd);
    return (0);
}

int child_navy(pid_t pid, char *path)
{
    FILE *f_stdin = cr_get_redirected_stdin();
    char **map[2] = {NULL, NULL};
    char *msg = rf("");
    int result;

    set_arg("tests/sol_ply1", &msg);
    fprintf(f_stdin, msg);
    free(msg);
    fclose(f_stdin);
    result = player_b(pid, path, map);
    destroy_map(map);
    return (result);
}

int parent_navy(char *path)
{
    FILE *f_stdin = cr_get_redirected_stdin();
    char **map[2] = {NULL, NULL};
    char *msg = rf("");
    int result;

    set_arg("tests/sol_ply1", &msg);
    fprintf(f_stdin, msg);
    free(msg);
    fclose(f_stdin);
    result = player_a(path, map);
    destroy_map(map);
    return (result);
}

Test(matchstick, test_simple_a, .init = cr_redirect_stdout)
{
    pid_t pid = getpid();
    int child_pid = fork();

    usleep(1000000);
    if (child_pid == -1)
        exit(84);
    if (child_pid == 0) {
        usleep(50000);
        cr_assert_eq(1, child_navy(pid, "tests/ply1"));
        kill(getpid(), 1);
    } else {
        cr_assert_eq(0, parent_navy("tests/ply2"));
        usleep(100000);
    }
}

Test(matchstick, test_simple_b, .init = cr_redirect_stdout)
{
    pid_t pid = getpid();
    int child_pid = fork();

    usleep(1000000);
    usleep(1000000);
    if (child_pid == -1)
        exit(84);
    if (child_pid == 0) {
        cr_assert_eq(0, parent_navy("tests/ply2"));
        kill(getpid(), 1);
    } else {
        usleep(50000);
        cr_assert_eq(1, child_navy(child_pid, "tests/ply1"));
        usleep(100000);
    }
}

Test(matchstick, test_spe_map_a, .init = cr_redirect_stdout)
{
    char **map[2] = {NULL, NULL};
    char *path;

    usleep(3000000);
    destroy_map(map);
    cr_assert_eq(84, player_a("", map));
    cr_assert_eq(84, player_b(0, "", map));
    cr_assert_eq(84, player_b(1, "", map));
    cr_assert_eq(84, craft_map("", map));
    for (int i = 1 ; i <= 17 ; i++) {
        map[0] = NULL;
        map[1] = NULL;
        path = rf("tests/error_map%d", i);
        cr_assert_eq(84, craft_map(path, map));
        destroy_map(map);
        free(path);
    }
}
