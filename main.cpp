#include "Lexer.hpp"

int  tree_flg = 0;
int  l_flg = 0;

int main(int ac, char **av)
{
    int     i;

    i = 1;
    (void)ac;
    if (av[i] && strcmp(av[i], "--tree") == 0)
        tree_flg = i++;
    if (av[i] && strcmp(av[i], "-l") == 0)
        l_flg = i++;
    Lexer lex(av[i]);
    lex.launchManager();
    
    return (0);
}