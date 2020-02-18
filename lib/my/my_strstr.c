/*
** EPITECH PROJECT, 2018
** my_strstr
** File description:
** display a parte of a str from a combinaison of caractère
*/

#include <criterion/criterion.h>

char *my_strstr(char *str, char const *to_find);
int check_if(char *str, char const *to_find, int i);
int my_str_len(char *str);

char *my_strstr(char *str, char const *to_find)
{
    int i;
    int checked = 0;

    for (i = 0 ; str[i] != '\0' && !checked ; i++)
        if (str[i] == to_find[0])
            checked = check_if(str, to_find, i);
    if (checked)
        return (&str[i - 1]);
    else
        return (0);
}

int check_if(char *str, char const *to_find, int i)
{
    for (int y = 0 ; to_find[y] != '\0' ; y++)
        if (str[i + y] != to_find[y])
            return (0);
    return (1);
}

int my_str_len(char *str)
{
    int j = 0;

    while (str[j] != '\0')
        j++;
    return (j);
}
