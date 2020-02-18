/*
** EPITECH PROJECT, 2018
** my_is_prime.c
** File description:
** check if it's a prime number
*/

int my_is_prime(int nb)
{
    if (nb <= 1)
        return (0);
    for (int i = 2 ; i != nb ; i++) {
        if (nb % i == 0)
            return (0);
    }
    return (1);
}
