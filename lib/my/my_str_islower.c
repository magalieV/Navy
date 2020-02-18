/*
** EPITECH PROJECT, 2018
** my_str_islower
** File description:
** check if there is only alphabet
*/

int my_str_islower(char *str);

int my_str_islower(char *str)
{
    for (int i = 0 ; str[i] ; i++)
        if (!(str[i] > 96 && str[i] < 123))
            return (0);
    return (1);
}
