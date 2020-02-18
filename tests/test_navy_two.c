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

Test(matchstick, test_spe_a, .init = cr_redirect_stdout)
{
    int ref[5] = {1, 2, 3, 4, 0};

    cr_assert_eq(0, eq_int_in_array(6, ref, 0));
}

Test(matchstick, test_spe_b, .init = cr_redirect_stdout)
{
    char **map[2] = {NULL, NULL};

    map[0] = malloc(sizeof(char *) * 4);
    map[0][2] = my_strdup("222222222222222");
    cr_assert_eq(84, size_chip(map, '2'));
    cr_assert_eq(84, size_chip(map, '1'));
    free(map[0][2]);
    free(map[0]);
}

Test(matchstick, test_spe_c, .init = cr_redirect_stdout)
{
    char **map[2] = {NULL, NULL};
    char uff[8] = "2:A1:A2";

    map[0] = malloc(sizeof(char *) * 4);
    map[0][2] = my_strdup("222222222222222");
    cr_assert_eq(84, craft_map_navy_two(uff, map));
    cr_assert_eq(84, craft_map_navy_one(uff, map));
}
