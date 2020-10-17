#ifndef TOKEN_HPP
# define TOKEN_HPP

#include <iostream>
#include "Enum.hpp"

class Token
{
    public:
        Token(std::string & tok, Delim type);
        void     setLR_tree(Token *tree, int rl);
        Token    *advancedTree(Token *top);
        Token    *getTree(int rl);

        std::string     tok;
        Delim           type;

    private:
        Token           *_ltree;
        Token           *_rtree;
};

#endif
