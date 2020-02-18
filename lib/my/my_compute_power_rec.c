/*
** EPITECH PROJECT, 2018
** my_compute_power_rec.c
** File description:
** return x ^ y
*/

int my_compute_power_rec(int nb, int p);

int my_compute_power_rec(int nb, int p)
{
    int result = nb;

    if (p == 0)
        return (1);
    if (p < 0)
        return (0);
    else if (p == 1)
        return (nb);
    result *= my_compute_power_rec(nb, p - 1);
    if (result > 2147483647)
        return (0);
    return (result);
}
