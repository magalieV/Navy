/*
** EPITECH PROJECT, 2018
** my_strncat
** File description:
** stick an str to an over
*/

char *my_strncat(char *dest, char const *src, int nb);
int my_strlen(char const *str);

char *my_strncat(char *dest, char const *src, int nb)
{
    int dest_len = my_strlen(dest);
    int i;

    for (i = 0 ; i < nb &&  src[i] ; i++)
        dest[dest_len + i] = src[i];
    dest[dest_len + i] = 0;
    return (dest);
}
