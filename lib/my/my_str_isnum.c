/*
** EPITECH PROJECT, 2018
** my_str_isnum
** File description:
** check if there is only num
*/

int my_str_isnum(char *str);

int my_str_isnum(char *str)
{
    for (int i = 0 ; str[i] ; i++)
        if (!(str[i] > 47 && str[i] < 58))
            return (0);
    return (1);
}
