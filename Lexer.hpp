#ifndef LEXER_HPP
# define LEXER_HPP

#include <list>
#include <fstream>
#include <regex>
#include "Exceptions.hpp"
#include "Token.hpp"
#include "Enum.hpp"

class Lexer
{ 
    public:
        Lexer(const char *file);
        void    tokenize(std::string & line);
        Delim   identifier(char c);
        void    newToken(std::string & tok, Delim t, int rl);
        void    binaryPrint() const;
        void    binaryBranch(Token *start) const;
        int     parse() const;
        bool    opValid(std::string & op) const;
        void    identifier(Token *curr) const;
        bool    opFuncs(std::string & params) const;
        void    deleteTree(Token *start);
        int    launchManager();
        ~Lexer();


    private:
        std::list <Token *>    _lst;
        const char             *_to;
};

#endif