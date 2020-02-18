/*
** EPITECH PROJECT, 2018
** my_find_prime_sup
** File description:
** return the smallest prime number >= nb
*/

int my_find_prime_sup(int nb);
int is_it_prime(int nb);

int my_find_prime_sup(int nb)
{
    if (nb <= 2)
        return (2);
    while (!is_it_prime(nb) && nb != 2147483647) {
        nb++;
    }
    if (nb != 2147483647)
        return (nb);
    else
        return (0);
}

int is_it_prime(int nb)
{
    if (nb <= 1)
        return (0);
    for (int i = 2 ; i != nb ; i++) {
        if (nb % i == 0)
            return (0);
    }
    return (1);
}
