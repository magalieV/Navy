/*
** EPITECH PROJECT, 2018
** my_str_isupper
** File description:
** check if there is only alphabet
*/

int my_str_isupper(char *str);

int my_str_isupper(char *str)
{
    for (int i = 0 ; str[i] ; i++)
        if (!(str[i] > 64 && str[i] < 91))
            return (0);
    return (1);
}
