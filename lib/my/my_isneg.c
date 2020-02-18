/*
** EPITECH PROJECT, 2018
** my_isneg.c
** File description:
** Detect if it's negativ or positiv
*/

int my_isneg(int n);
void my_putchar(char c);

int my_isneg(int n)
{
    if (n >= 0)
        my_putchar('P');
    else
        my_putchar('N');
    return (0);
}
