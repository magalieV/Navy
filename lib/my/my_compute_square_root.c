/*
** EPITECH PROJECT, 2018
** my_compute_square_root.c
** File description:
** retrun the square root of nb
*/

int divisional_tracking(int const nb, int min, int max);
int my_compute_square_root(int nb);

int my_compute_square_root(int nb)
{
    int min = 1;
    int max = 46340;

    if (nb <= 0 || nb > 2147395600 || nb == 2)
        return (0);
    return (divisional_tracking(nb, min, max));
}

int divisional_tracking(int const nb, int min, int max)
{
    int track;

    if (min * min == nb)
        return (min);
    else if (max * max == nb)
        return (max);
    track = (min + (max - min) / 2);
    if (track == min)
        return (0);
    if (track * track > nb)
        return (divisional_tracking(nb, min, track));
    else
        return (divisional_tracking(nb, track, max));
}
