/*
** EPITECH PROJECT, 2018
** my_strupcase
** File description:
** lower a str
*/

char *my_strlowcase(char *str);

char *my_strlowcase(char *str)
{
    for (int i = 0 ; str[i] ; i++)
        if (str[i] > 64 && str[i] < 91)
            str[i] = str[i] - 65 + 97;
    return (str);
}
