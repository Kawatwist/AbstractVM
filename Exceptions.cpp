#include "Exceptions.hpp"

const char *LexicalException::what() const throw()
{
    return "Lexical error";
}

const char  *SyntacticException::what() const throw()
{
    return "Syntactic error";
}

const char  *ExitLexicalException::what() const throw()
{
    return "exit expected";
}