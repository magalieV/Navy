/*
** EPITECH PROJECT, 2018
** my_strncmp
** File description:
** compar n char from two str
*/

int my_strncmp(char const *s1, char const *s2, int n);
int s1_len(char const *s1);
int s2_len(char const *s2);

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = s1_len(s1);
    int y = s2_len(s2);

    for (int j = 0 ; s1[j] != '\0' && i >= y && j < n; j++) {
        if (s1[j] == '\0' && s2[j] != '\0')
            return (-s2[j]);
        if (s1[j] != '\0' && s2[j] == '\0')
            return (s1[j]);
        if (s1[j] != s2[j])
            return (s1[j] - s2[j]);
    }
    for (int j = 0 ; s2[j] != '\0' && i < y && j < n; j++) {
        if (s1[j] == '\0' && s2[j] != '\0')
            return (-s2[j]);
        if (s1[j] != '\0' && s2[j] == '\0')
            return (s1[j]);
        if (s1[j] != s2[j])
            return (s1[j] - s2[j]);
    }
    return (0);
}

int s1_len(char const *s1)
{
    int i;

    for (i = 0 ; s1[i] ; i++)
        continue;
    return (i);
}

int s2_len(char const *s2)
{
    int y;

    for (y = 0 ; s2[y] ; y++)
        continue;
    return (y);
}
