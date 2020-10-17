#ifndef EXCEPTIONS_HPP
# define EXCEPTIONS_HPP

#include <iostream>


class LexicalException : public std::exception
{
    virtual const char* what() const throw();
};

class LexicalOpException : public std::exception
{
    virtual const char* what() const throw();
};

class SyntacticException : public std::exception
{
    virtual const char* what() const throw();
};

class ExitLexicalException : public std::exception
{
    virtual const char *what() const throw();
};

#endif