/*
** EPITECH PROJECT, 2018
** my_strupcase
** File description:
** UPPER a str
*/

char *my_strupcase(char *str);

char *my_strupcase(char *str)
{
    for (int i = 0 ; str[i] ; i++)
        if (str[i] > 96 && str[i] < 123)
            str[i] = str[i] + 65 - 97;
    return (str);
}
