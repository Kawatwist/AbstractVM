#include "Lexer.hpp"

extern int tree_flg;
extern int l_flg;

Lexer::Lexer(const char *file) : _to(file)
{
    std::string           line;
    std::ifstream         fd;

    if (file)
    {
        fd.open(file);
        if (!fd.is_open())
        {
            std::cerr << "Error " << strerror(errno) << std::endl;
            exit(1);
        }
    }
    while (std::getline(!fd.is_open() ? std::cin : fd, line))
    {
        if (!fd.is_open() && !line.compare(";;"))
            break ;
        Lexer::tokenize(line);
    }
    fd.close();
    if (tree_flg)
        this->binaryPrint();
    if (this->_lst.size() == 0 || this->parse())
        exit(1);
}

void Lexer::binaryPrint() const
{
    int     i;

    i = 0;
    for (auto v : this->_lst)
    {
        std::cout << "-----------TOKEN " << i << " =>-------------" << std::endl;
        std::cout << "\tTree => " <<  v->tok << " " << v->type << std::endl;
        if (v->getTree(1))
        {
            std::cout << "\t/\t\t\t\\" << std::endl;
            std::cout << v->getTree(1)->tok;
            std::cout << " " <<  v->getTree(1)->type;
            if (v->getTree(0))
                this->binaryBranch(v->getTree(0));
        }
        i++;
        std::cout << std::endl;
    }
}

void Lexer::binaryBranch(Token *start) const
{
    if (start)
    {
        std::cout << "\t\t\t\t" << start->tok << " " << start->type << std::endl;

        this->binaryBranch(start->getTree(0));
    }
}

void Lexer::tokenize(std::string & line)
{
    size_t          beg = 0, pos = 0, cond = 1;
    char            *p;
    std::string     tok;

    p = const_cast<char *>(line.c_str());
    while (p[pos] && p[pos] != '\n')
    {
        while (p[pos] && (p[pos] == ' ' || p[pos] == '\t'))
            pos++;
        if (strchr(p + pos, ';'))
        {
            beg = pos;
            while (p[beg] && p[beg] != ';')
                beg++;
            tok = std::string(p + beg + 1, p + strlen(p));
            p[beg] = 0;
            this->newToken(tok, COMMENT, 1);
        }
        beg = pos;
        while (p[beg] && (p[beg] != ' ' && p[beg] != '\t'))
            beg++;
        tok = std::string(p + pos, p + beg);
        if (tok.find("(") != std::string::npos)
        {
            std::string tmp = tok.substr(0, tok.find("("));
            if (tmp.size())
                this->newToken(tmp, FUNC, cond++);
            tok = tok.substr(tok.find("("), tok.size());
            if (tok.size())
                this->newToken(tok, PARAMS, cond);
        }
        else
        {
            if (tok.size())
                this->newToken(tok, cond == 1 ? OP : PARAMS, cond);
        }
        pos = beg;
        cond++;
    }
}

void        Lexer::newToken(std::string & tok, Delim t, int rl)
{
    Token   *token = new Token(tok, t);

    if (rl == 1)
        this->_lst.push_back(token);
    else if (rl == 2)
        this->_lst.back()->setLR_tree(token, 1);
    else
        this->_lst.back()->advancedTree(this->_lst.back())->setLR_tree(token, 0);
}

int       Lexer::parse() const
{
    int     line = 0;
    int     err = 0;
    if (l_flg)
    {
        for (auto v : this->_lst)
        {
            if (v->type != COMMENT)
                line++;
            try
            {
                this->identifier(v);
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << " on line " << line <<'\n';
                err++;
            }    
        }
        try {
            if (strcmp(this->_lst.back()->tok.c_str(), "exit"))
                throw ExitLexicalException();
        }
        catch(const std::exception& e)
        {
            err++;
            std::cerr << "Expected exit on line " << line + 1 <<'\n';
        }
    }
    else
    {
        try
        {
            for (auto v : this->_lst)
            {
                if (v->type != COMMENT)
                    line++;
                this->identifier(v);
            }
            if (strcmp(this->_lst.back()->tok.c_str(), "exit"))
                throw ExitLexicalException();
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << " on line " << line <<'\n';
            err++;
        }   
    }
    return err;
}

bool    Lexer::opValid(std::string & op) const
{
    static const char *tab[] = {"push", "pop",
        "dump", "assert", "add", "sub",
        "mul", "div", "mod", "print", "exit"
    };

    for (size_t i = 0; i < sizeof(tab) / sizeof(tab[0]); i++)
    {
        if (strcmp(op.c_str(), tab[i]) == 0)
            return true;
    }
    return false;
}

bool    Lexer::opFuncs(std::string & param) const
{
    static const char *tab[] = {"int8", "int16", "int32", "float", "double"};

    for (size_t i = 0; i < sizeof(tab) / sizeof(tab[0]); i++)
    {
        if (strcmp(param.c_str(), tab[i]) == 0)
            return true;
    }
    return false;
}

void    Lexer::identifier(Token *curr) const
{
    if (curr->type == COMMENT)
        return ;
    if (curr->type != OP)
        throw SyntacticException();
    if (!opValid(curr->tok))
        throw SyntacticException();
    if (!strcmp("push", curr->tok.c_str()) || !strcmp("assert", curr->tok.c_str()))
    {
        if (!curr->getTree(1))
            throw LexicalException();
        if (!opFuncs(curr->getTree(1)->tok))
            throw LexicalException();
        if (!curr->getTree(0) || curr->getTree(0)->getTree(0))
            throw SyntacticException();
        if (curr->getTree(0)->tok.at(0) != '(' || curr->getTree(0)->tok.back() != ')')
            throw SyntacticException();
        if (!std::regex_match (curr->getTree(0)->tok.substr(1, curr->getTree(0)->tok.size() - 2), std::regex("[-]?([0-9]+([.][0-9]*)?|[.][0-9]+)") ))
            throw LexicalException();
    }
    // if (!strcmp("assert", curr->tok.c_str()))
    // {
    //     if (!curr->getTree(1))
    //         throw LexicalException();
    //     if (!opFuncs(curr->getTree(1)->tok))
    //         throw LexicalException();
    //     if (!curr->getTree(0) || curr->getTree(0)->getTree(0))
    //         throw SyntacticException();
    //     if (curr->getTree(0)->tok.at(0) != '(' || curr->getTree(0)->tok.back() != ')')
    //         throw SyntacticException();
    //     if (!std::regex_match (curr->getTree(0)->tok.substr(1, curr->getTree(0)->tok.size() - 2), std::regex("[-]?([0-9]+([.][0-9]*)?|[.][0-9]+)") ))
    //         throw LexicalException();
    // }
}

void    Lexer::deleteTree(Token *start)
{
    if (start && start->getTree(0))
        this->deleteTree(start->getTree(0));
    delete start;
}

void    Lexer::launchManager() const
{
    for (auto v : this->_lst)
    {
        // IOperand * const op = CreateType(v->getTree(1), v->getTree(0));

    }
}

Lexer::~Lexer()
{
    for (auto v : this->_lst)
    {
        this->deleteTree(v->getTree(0));
        this->deleteTree(v->getTree(1));
        delete v;
    }
}