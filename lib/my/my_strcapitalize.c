/*
** EPITECH PROJECT, 2018
** my_strcapitalize
** File description:
** UPPER fisrt letter of a str
*/

char *my_strcapitalize(char *str);
char modif_str(char *str, int i);

char *my_strcapitalize(char *str)
{
    for (int i = 0 ; str[i] ; i++)
        if (str[i] > 64 && str[i] < 91)
            str[i] = str[i] - 65 + 97;
    if (str[0] > 96 && str[0] < 123)
        str[0] = str[0] + 65 - 97;
    for (int i = 1 ; str[i] ; i++)
        if (str[i] > 96 && str[i] < 123)
            str[i] = modif_str(str, i);
    return (str);
}

char modif_str(char *str, int i)
{
    if (!(str[i - 1] > 96 && str[i - 1]) &&
        !(str[i - 1] > 64 && str[i - 1] < 91))
        str[i] = str[i] + 65 - 97;
    return (str[i]);
}
