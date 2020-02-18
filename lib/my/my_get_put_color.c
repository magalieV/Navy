/*
** EPITECH PROJECT, 2018
** my_get_put_color.c
** File description:
** get a colored str
*/

#include "my.h"
#include <unistd.h>

const struct color_s COLOR[] = {
    {"bl", "\033[22;34m"}, {"re", "\033[22;31m"},
    {"gn", "\033[22;32m"}, {"br", "\033[22;33m"},
    {"bl", "\033[22;34m"}, {"ma", "\033[22;35m"},
    {"cy", "\033[22;36m"}, {"gr", "\033[22;37m"},
    {"pu", "\033[22;35m"}, {"bk", "\033[22;30m"},
    {"lbl", "\033[22;01;34m"}, {"lre", "\033[22;01;31m"},
    {"lgn", "\033[22;01;32m"}, {"lbr", "\033[22;01;33m"},
    {"lbl", "\033[22;01;34m"}, {"lma", "\033[22;01;35m"},
    {"lcy", "\033[22;01;36m"}, {"lgr", "\033[22;01;37m"},
    {"lpu", "\033[22;01;35m"}, {"lbk", "\033[22;01;30m"},
    {"dbl", "\033[22;02;34m"}, {"dre", "\033[22;02;31m"},
    {"dgn", "\033[22;02;32m"}, {"dbr", "\033[22;02;33m"},
    {"dbl", "\033[22;02;34m"}, {"dma", "\033[22;02;35m"},
    {"dcy", "\033[22;02;36m"}, {"dgr", "\033[22;02;37m"},
    {"dpu", "\033[22;02;35m"}, {"dbk", "\033[22;02;30m"},
    {"ldbl", "\033[22;01;02;34m"}, {"ldre", "\033[22;01;02;31m"},
    {"ldgn", "\033[22;01;02;32m"}, {"ldbr", "\033[22;01;02;33m"},
    {"ldbl", "\033[22;01;02;34m"}, {"ldma", "\033[22;01;02;35m"},
    {"ldcy", "\033[22;01;02;36m"}, {"ldgr", "\033[22;01;02;37m"},
    {"ldpu", "\033[22;01;02;35m"}, {"ldbk", "\033[22;01;02;30m"},
    {"l", "\033[01m"}, {"d", "\033[02m"}, {"r", "\033[22m"},
    {"i", "\033[3m"}, {"-", "\033[9m"},
    {"--", "\033[21m"}, {"_", "\033[4m"},
    {"1/2", "\033[5m"}, {"#f", "\033[7m"},
    {"#t", "\033[8m"}, {"0", "\033[0m"}
};

char *display_help_color(void)
{
    my_putstr("\n\033[22;01;34m\033[21mHelp for color %; -h\n\n");
    for (int i = 0 ; i != 51 ; i++){
        my_putstr("\e[0m");
        my_putstr(COLOR[i].name);
        write(1, ":\t|", 3);
        my_putstr(COLOR[i].core);
        write(1, "This is the result\n", 19);
    }
    return (my_strdup("\e[0m"));
}

char *my_get_put_color(char *src)
{
    int len = 9;
    if (!my_strcmp(src, "-h"))
        return (display_help_color());
    for (int i = 0 ; i != 51 ; i++)
        if (!my_strcmp(COLOR[i].name, src))
            return (my_strdup(COLOR[i].core));
    return (my_strdup("\x1b[0m"));
}
