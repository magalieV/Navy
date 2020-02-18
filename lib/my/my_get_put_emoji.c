/*
** EPITECH PROJECT, 2018
** my_get_put_color.c
** File description:
** get a colored str
*/

#include "my.h"
#include "unistd.h"

const struct color_s EMOJI[] = {
    {"bee", "\U0001F41D"}, {"fish", "\U0001F41F"}, {"chick", "\U0001F424"},
    {"chick_egg", "\U0001F423"}, {"turle", "\U0001F422"}, {"wc", "\U0001F6BE"},
    {"koala", "\U0001F428"}, {"dog", "\U0001F415"}, {"camel", "\U0001F42B"},
    {"dauphin", "\U0001F42C"}, {"jew", "\U00002721"}, {"peace", "\U0000262E"},
    {"science", "\U0000269B"}, {"catho", "\U0000271D"}, {"bio", "\U00002623"},
    {"ract", "\U00002622"}, {"pegi18", "\U0001F51E"}, {"dna", "\U0001F9EC"},
    {"warning", "\U000026A0"}, {"bed", "\U0001F6CF"}, {"potion", "\U0001F9EA"},
    {"magnet", "\U0001F9F2"}, {"link", "\U0001F517"}, {"chains", "\U000026D3"},
    {"shield", "\U0001F6E1"}, {"bow", "\U0001F3F9"}, {"c_sword", "\U00002694"},
    {"dagger", "\U0001F5E1"}, {"ham_w", "\U0001F6E0"}, {"pick", "\U000026CF"},
    {"ham_p", "\U00002692"}, {"hammer", "\U0001F528"}, {"ham", "\U0001F528"},
    {"key", "\U0001F511"}, {"old_key", "\U0001F5DD"}, {"locked", "\U0001F512"},
    {"unlocked", "\U0001F513"}, {"dir", "\U0001F4C1"}, {"dir_o", "\U0001F4C2"},
    {"locked_d", "\U0001F510"}, {"pen", "\U0001F58A"}, {"memo", "\U0001F4DD"},
    {"calender", "\U0001F4C5"}, {"e_mail", "\U0001F4E7"}, {"yen", "\U0001F4B4"},
    {"paperclip", "\U0001F4CE"}, {"mail", "\U00002709"}, {"euro", "\U0001F4B5"},
    {"scissors", "\U00002702"}, {"pound", "\U0001F4B7"}, {"card", "\U0001F4B3"},
    {"pushpin", "\U0001F4CC"}, {"book", "\U0001F4D5"}, {"book_o", "\U0001F4D6"},
    {"package", "\U0001F4E6"}, {"book_g", "\U0001F4D7"}, {"file", "\U0001F4C4"},
    {"book_b", "\U0001F4D8"}, {"book_y", "\U0001F4D9"}, {"nbook", "\U0001F4D3"},
    {"scroll", "\U0001F4DC"}, {"light", "\U0001F4A1"}, {"candel", "\U0001F56F"},
    {"search", "\U0001F50D"}, {"camera", "\U0001F4F7"}, {"disk", "\U0001F4BF"},
    {"keyoard", "\U00002328"}, {"mouse", "\U0001F5B1"}, {"radio", "\U0001F4FB"},
    {"printer", "\U0001F5A8"}, {"laptop", "\U0001F4BB"}, {"dvd", "\U0001F4C0"},
    {"computer", "\U0001F5A5"}, {"phone", "\U0001F4DE"}, {"drum", "\U0001F941"},
    {"musical_s", "\U0001F3BC"}, {"micro", "\U0001F3A4"}, {"tv", "\U0001F4FA"},
    {"musical_n", "\U0001F3B5"}, {"bell", "\U0001F514"}, {"ring", "\U0001F48D"},
    {"musical_ns", "\U0001F3B6"}, {"gem", "\U0001F48E"}, {"ring", "\U0001F48D"},
    {"guitar", "\U0001F3B8"}, {"violin", "\U0001F3BB"}, {"muted", "\U0001F507"},
    {"crown", "\U0001F451"}, {"shoe", "\U0001F45F"}, {"highshoe", "\U0001F460"},
    {"spade", "\U00002660"}, {"heart", "\U00002665"}, {"diamond", "\U00002666"},
    {"heart", "\U00002665"}, {"soccer", "\U000026BD"}, {"basket", "\U0001F3C0"},
    {"medal", "\U0001F396"}, {"trophy", "\U0001F3C6"}, {"place1", "\U0001F947"},
    {"place2", "\U0001F948"}, {"place3", "\U0001F949"}, {"gift", "\U0001F381"},
    {"tree_c", "\U0001F384"}, {"droplet", "\U0001F4A7"}, {"fire", "\U0001F525"},
    {"snow", "\U00002744"}, {"volt", "\U000026A1"}, {"rainbow", "\U0001F308"},
    {"star", "\U00002B50"}, {"start_g", "\U0001F320"}, {"moon_f", "\U0001F315"},
    {"moon", "\U0001F319"}, {"clock", "\U0001F550"}, {"airplane", "\U00002708"},
    {"meat", "\U0001F356"}, {"butterfly", "\U0001F98B"}, {"time", "\U000023F3"},
    {"shark", "\U0001F988"}, {"snake", "\U0001F40D"}, {"dragon", "\U0001F409"},
    {"panda", "\U0001F43C"}, {"rabbit", "\U0001F407"}, {"mouse", "\U0001F401"},
    {"goat", "\U0001F410"}, {"unicron", "\U0001F984"}, {"tiger", "\U0001F405"},
    {"wolf", "\U0001F43A"}, {"gandalf", "\U0001F9D9"}, {"santa", "\U0001F385"},
    {"superman", "\U0001F9B8"}, {"girl", "\U0001F467"}, {"mouth", "\U0001F444"},
    {"pray", "\U0001F64F"}, {"clap", "\U0001F44F"}, {"bro_fist", "\U0001F44A"},
    {"meme_review", "\U0001F44F"}, {"boy", "\U0001F466"}, {"cat", "\U0001F431"},
    {"fist", "\U0001F44A"}, {"thumbs_up", "\U0001F44D"}, {"fox", "\U0001F98A"},
    {"fine", "\U0001F44C"}, {"100", "\U0001F4A2"}, {"collision", "\U0001F4A5"},
    {"pig", "\U0001F416"}, {"doplets", "\U0001F4A6"}, {"dizzy", "\U0001F4AB"},
    {"heart_r", "\U00002764"}, {"heart_o", "\U0001F9E1"}, {"cow", "\U0001F404"},
    {"heart_y", "\U0001F49B"}, {"heart_g", "\U0001F49A"}, {"rat", "\U0001F400"},
    {"heart_b", "\U0001F499"}, {"heart_p", "\U0001F49C"}, {"sun", "\U00002600"},
    {"heart_d", "\U0001F5A4"}, {"skull", "\U0001F480"}, {"death", "\U00002620"},
    {"swear", "\U0001F92C"}, {"poo", "\U0001F4A9"}, {"tree", "\U0001F333"},
    {"flower", "\U0001F940"}, {"tulip", "\U0001F337"}, {"seed", "\U0001F331"},
    {"duck", "\U0001F986"},
    {"blackL", "\U00002B1B"}, {"whiteL", "\U00002B1C"},
    {"blackl", "\U000025FC"}, {"whitel", "\U000025FB"},
    {"blackm", "\U000025FE"}, {"whitem", "\U000025FD"},
    {"blacks", "\U000025AA"}, {"whites", "\U000025AB"},
    {"black_c", "\U000026AB"}, {"white_c", "\U000026AA"},
    {":)", "\U0001F600"}, {": )", "\U0001F603"}, {":D", "\U0001F601"},
    {"x)", "\U0001F606"}, {":')", "\U0001F605"}, {"x')", "\U0001F923"},
    {";)", "\U0001F609"}, {":<3", "\U0001F618"}, {":3", "\U0001F617"},
    {":p", "\U0001F61B"}, {";p", "\U0001F61C"}, {"xp", "\U0001F61D"},
    {"-_-", "\U0001F610"}, {":)", "\U0001F600"}
};

char *display_help_emoji(void)
{
    my_putstr("\n\033[22;01;34m\033[21mHelp for emoji %; -h\n\n");
    my_putstr("\033[0m");
    for (int i = 0 ; i != 185 ; i++){
        my_putstr(EMOJI[i].core);
        write(1, ":\t|", 3);
        my_putstr(EMOJI[i].name);
        write(1, "\n", 1);
    }
    return (my_strdup("\U0001F41D"));
}

char *my_get_put_emoji(char *src)
{
    if (!my_strcmp(src, "-h"))
        return (display_help_emoji());
    for (int i = 0 ; i != 185 ; i++)
        if (!my_strcmp(EMOJI[i].name, src))
            return (my_strdup(EMOJI[i].core));
    return (my_strdup("\U0001F41D"));
}
