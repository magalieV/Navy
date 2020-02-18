/*
** EPITECH PROJECT, 2018
** my_strcat
** File description:
** stick an str to an over
*/

char *my_strcat(char *dest, char const *src);
int my_strlen(char *str);

char *my_strcat(char *dest, char const *src)
{
    int dest_len = my_strlen(dest);
    int i;

    for (i = 0 ; src[i] ; i++)
        dest[dest_len + i] = src[i];
    dest[dest_len + i] = '\0';

    return (dest);
}
