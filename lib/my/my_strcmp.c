/*
** EPITECH PROJECT, 2018
** my_strcmp
** File description:
** compare str length
*/

int my_strfcmp(char const *s1, char const *s2);
int which(char const *s1, char const *s2, int i);

int eq_str(char const *s1, char const *s2)
{
    for	(int i = 0; s1[i] || s2[i]; i++)
        if (s1[i] != s2[i])
            return (0);
    return (1);
}

int my_strcmp(char const *s1, char const *s2)
{
    for (int i = 0; s1[i] || s2[i]; i++)
        if (s1[i] != s2[i])
            return (s1[i] - s1[2]);
    return (0);
}

int my_strfcmp(char const *s1, char const *s2)
{
    int i;
    int y;

    for (i = 0 ; s1[i] ; i++)
        continue;
    for (y = 0 ; s2[y] ; y++)
        continue;
    for (int j = 0 ; s1[j] != '\0' && i >= y; j++) {
        if (s1[j] != s2[j]) {
            return (which(s1, s2, j));
        }
    }
    for (int j = 0 ; s2[j] != '\0' && i < y; j++) {
        if (s1[j] != s2[j]) {
            return (which(s1, s2, j));
        }
    }
    return (0);
}

int which(char const *s1, char const *s2, int j)
{
    if (s1[j] > s2[j])
        return (1);
    return (-1);
}
