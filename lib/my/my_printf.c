/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include <stddef.h>
#include "my.h"

const struct printf_func PF_FUNC[] = {
    {'c', &my_get_putchar},
    {'s', &my_strdup},
    {'S', &my_get_stroctal},
    {'d', &my_get_put_nbr},
    {'i', &my_get_put_nbr},
    {'u', &my_get_put_unsignednbr},
    {'o', &my_get_put_base_octal},
    {'x', &my_get_put_base_hexa_min},
    {'p', &my_get_put_base_hexa_void},
    {'X', &my_get_put_base_hexa_cap},
    {'b', &my_get_put_base_binaire},
    {';', &my_get_put_color},
    {':', &my_get_put_emoji},
    {'$', &my_strdup},
    {'!', &my_returnstr},
    {'>', &my_get_to_line},
};

int find_tag(char *str)
{
    int i = 0;
    int nb = 0;
    char c;

    while (str[i]) {
        if (str[i] == '%') {
            i++;
            nb++;
        }
        if (str[i])
            i++;
    }
    return (nb);
}

char *number_merge(char *src, char *nb, char akaa)
{
    char *str;
    int nb_val = my_getnbr(nb);
    int dif_len = nb_val - my_strlen(src);
    char c = (nb[0] == 48) ? (48) : (32);

    free(nb);
    if (akaa == '$' || akaa == '!')
        return (my_get_putstrmax(src, nb_val));
    if (dif_len <= 0)
        return (src);
    str = my_xmalloc(nb_val + 1);
    for (int i = 0 ; i != dif_len ; i++)
        str[i] = c;
    for (int j = 0 ; src[j] ; j++)
        str[dif_len + j] = src[j];
    str[nb_val] = 0;
    free(src);
    return (str);
}

char *engage_function(char *src, va_list *ap, int *idx)
{
    char *str = NULL;
    char *nb = NULL;
    int done = 0;

    for (*idx = *idx + 1 ; src[*idx] == ' ' ; (*idx)++);
    if (src[*idx] == '%') {
        str = my_xmalloc(2);
        str[0] = '%';
        return (str);
    }
    nb = (47 < src[*idx] && src[*idx] < 58) ? (number(src, idx)) : (NULL);
    for (int i = 0 ; i != 16 ; i++)
        if (src[*idx] == PF_FUNC[i].func) {
            str = PF_FUNC[i].displayfunc(va_arg(*ap, long));
            done = 1;
        }
    str = (done) ? (str) : (my_xmalloc(1));
    str = (nb != NULL) ? (number_merge(str, nb, src[*idx])) : (str);
    return (str);
}

int display_advenced_str(char **array, char *str)
{
    int len = 0;
    int idx = 0;

    for (int i = 0 ; str[i] ; i++) {
        if (str[i] == '%') {
            my_putstr(array[idx]);
            len += my_strlen(array[idx]);
            free(array[idx++]);
        } else {
            write(1, &str[i], 1);
            len++;
        }
    }
    free(str);
    free(array);
    return (len);
}

int my_printf(char *src, ...)
{
    int nb = find_tag(src);
    char **array = malloc(sizeof(char *) * (nb + 1));
    char *str = my_xmalloc(my_strlen(src) + 1);
    int len = 0;
    int idx = 0;
    va_list ap;

    va_start(ap, src);
    array[nb] = NULL;
    nb = 0;
    for (int index = 0 ; src[index] ; index++) {
        str[idx++] = src[index];
        if (src[index] == '%')
            array[nb++] = engage_function(src, &ap, &index);
    }
    va_end(ap);
    len = display_advenced_str(array, str);
    return (len);
}
