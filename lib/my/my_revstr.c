/*
** EPITECH PROJECT, 2018
** my_revstr
** File description:
** return a reversed str
*/

char *my_revstr(char *str);
int my_evil_strlen(char *str);

char *my_revstr(char *str)
{
    int str_len = my_evil_strlen(str) - 1;
    char my_str;

    for (int i = str_len; i > 0 ; i--) {
        for (int y = 1 ; y <= i ; y++) {
            my_str = str[y];
            str[y] = str[y - 1];
            str[y - 1] = my_str;
        }
    }
    return (str);

}

int my_evil_strlen(char *str)
{
    int n_len = 0;

    while (*str != '\0') {
        n_len++;
        str++;
    }
    return (n_len);
}
