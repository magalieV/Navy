/*
** EPITECH PROJECT, 2018
** my_put_nbr.c
** File description:
** Display a number
*/

int my_put_nbr(int nb);
int len_number(int nb, int nb_len);
int my_pow(int nb, int expo);
int check_min(int nb);
void my_putchar(char c);

int my_put_nbr(int nb)
{
    int nb_len = 0;
    int nb_print = 0;

    if (nb == 0) {
        my_putchar(48);
    }
    if (check_min(nb) == 1) {
        if (nb < 0) {
            nb = -nb;
            my_putchar('-');
        }
        nb_len = len_number(nb, nb_len);
        for (int i = nb_len - 1 ; i != -1 ; i--) {
            nb_print = nb / my_pow(10, i);
            nb -= nb_print * my_pow(10, i);
            my_putchar(nb_print + 48);
        }
    }
}

int len_number(int nb, int nb_len)
{
    while (nb != 0) {
        nb = nb / 10;
        nb_len++;
    }
    return (nb_len++);
}

int my_pow(int nb, int expo)
{
    int nb_tamp = nb;

    if (expo == 0) {
        return (1);
    }
    for (int i = 1 ; i < expo ; i++) {
        nb *= nb_tamp;
    }
    return (nb);
}

int check_min(int nb)
{
    if (nb == -2147483648) {
        my_putchar('-');
        my_putchar('2');
        my_putchar('1');
        my_putchar('4');
        my_putchar('7');
        my_putchar('4');
        my_putchar('8');
        my_putchar('3');
        my_putchar('6');
        my_putchar('4');
        my_putchar('8');
        return (0);
    }
    return (1);
}
