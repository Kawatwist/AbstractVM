#include "Token.hpp"


Token::Token(std::string & tok, Delim type) : tok(tok), type(type), _ltree(nullptr), _rtree(nullptr)
{

}


void    Token::setLR_tree(Token *tree, int rl)
{

    if (rl)
        this->_ltree = tree;
    else
    {
        this->_rtree = tree;
    }
}

Token    *Token::getTree(int rl)
{
    if (rl)
        return (this->_ltree);
    else
        return (this->_rtree);
}

Token    *Token::advancedTree(Token *top)
{
    if (top->_rtree)
        return this->advancedTree(top->_rtree);
    return (top);
}