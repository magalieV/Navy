/*
** EPITECH PROJECT, 2018
** my_str_isinlexicode
** File description:
** return 1 if all the char in the str are in the lexicode else return 0
*/

#include "my.h"

int my_str_isinlexicode(char const *src, char const *lexicode)
{
    int lex_len = my_strlen(lexicode);
    int i = 0;

    for (int j = 0 ; src[i] ; j++) {
        if (src[i] == lexicode[j]) {
            j = -1;
            i++;
            continue;
        }
        if (j + 1 == lex_len)
            return (0);
    }
    return (1);
}
