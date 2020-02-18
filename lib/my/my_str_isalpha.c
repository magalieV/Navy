/*
** EPITECH PROJECT, 2018
** my_str_isalpha
** File description:
** check if there is only alphabet
*/

int my_str_isalpha(char *str);

int my_str_isalpha(char *str)
{
    for (int i = 0 ; str[i] ; i++)
        if (!(str[i] > 96 && str[i] < 123) && !(str[i] > 64 && str[i] < 91))
            return (0);
    return (1);
}
