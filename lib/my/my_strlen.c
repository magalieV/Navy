/*
** EPITECH PROJECT, 2018
** my_strlen.c
** File description:
** return the tail of a string value
*/

int my_strlen(char const *str);

int my_strlen(char const *str)
{
    int n_len = 0;

    while (str[n_len])
        n_len++;
    return (n_len);
}
