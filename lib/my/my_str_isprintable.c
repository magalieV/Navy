/*
** EPITECH PROJECT, 2018
** my_str_isprintable
** File description:
** check if there is only printable caractère
*/

int my_str_isprintable(char *str);

int my_str_isprintable(char *str)
{
    for (int i = 0 ; str[i] ; i++)
        if (!(str[i] > 31 && str[i] < 127))
            return (0);
    return (1);
}
