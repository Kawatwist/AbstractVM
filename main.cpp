#include "Lexer.hpp"
#include "./Includes/FactoryOperator.Class.hpp"
#include "./Includes/TypeOperator.Class.hpp"
#include "./Includes/MasterOperator.Class.hpp"

FactoryOperator  Factory;
MasterOperator   Manager;
int  tree_flg = 0;
int  l_flg = 0;
int  c_flg = 0;

int main(int ac, char **av)
{
    int     i;

    i = 1;
    (void)ac;
    if (av[i] && strcmp(av[i], "--tree") == 0)
        tree_flg = i++;
    if (av[i] && strcmp(av[i], "-l") == 0)
        l_flg = i++;
    if (av[i] && strcmp(av[i], "-c") == 0)
        c_flg = i++;
    Lexer lex(av[i]);
    return (lex.launchManager());
}