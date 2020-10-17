/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stack.Class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <lomasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 21:28:41 by lomasse           #+#    #+#             */
/*   Updated: 2020/10/15 15:23:49 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_CLASS
# define STACK_CLASS

#include <list>
#include "IOperand.Class.hpp"

typedef enum ExceptionStack
{
        EmptyStack = 0,
        StackError = 1,
        OverFlow = 2,
        UnderFlow = 3,
        ByZero = 4,
        NoExit = 5,
        UnknowInstruction = 6, 
        AssertNotTrue = 7,
        ArithmeticError = 8,
}       t_ExceptionStack;

class Stack
{
    public:
        /* Get */
        void            print_content(void) const;

        template < typename U >
        U               getValue(void)      const {return((static_cast<U>(this->_content)));}; //Convert to Original Type
        eOperandType    getType(void)       const;
        
        /* Constructor */
        Stack(std::string content, std::string type) : _content(content), _type(type), _next(NULL) {};
        ~Stack() {delete this->_next;};
        
    private:
        std::string     _content;
        eOperandType    _type;
        Stack *         _next;
};

class OperatorC : public IOperand
{
    public :
        void                CanOperate(void);
        /* Get */
        int                 getPrecision(void)  const;
        std::string const & toString(void)      const;
        eOperandType        getType(void)       const;
        Stack		        toType(std::string type, std::string value) const;
        eOperandType        FindType(eOperandType o1, eOperandType o2) const {return (o1 < o2 ? o1 : o2);}
        bool                HasBeenExit(void)   const;

        /* Opcode */
        void    OP_push(Stack toPush);
        void    OP_push(std::string type, std::string value);
        void    OP_pop(void);
        void    OP_dump(void) const;
        void    OP_assert(std::string type, std::string value);
        void    OP_add(void);
        void    OP_sub(void);
        void    OP_mul(void);
        void    OP_div(void);
        void    OP_mod(void);
        void    OP_print(void);
        void    OP_exit(void);

        /* Operator */
        IOperand const *operator+( IOperand const & rhs ) const;
        IOperand const *operator-( IOperand const & rhs ) const;
        IOperand const *operator*( IOperand const & rhs ) const;
        IOperand const *operator/( IOperand const & rhs ) const;
        IOperand const *operator%( IOperand const & rhs ) const;
        
        /* Exception */
        class StackException : public std::exception
        {
            public :
                StackException(int n) : _Error(n) {};
                virtual const char * what() const throw() {return (this->tab[this->_Error]);};
            private :
                const char tab[9][25] = {"EmptyStack", "StackException",
                    "OverFlowValue", "UnderFlowValue",
                    "Divide/Modulo by 0", "ProgramDontExit",
                    "UnknowInstruction", "AssertNotTrue",
                    "ArithmeticWithLessThan2"};
                int _Error;
        };

        /* Constructor */
        OperatorC(void * content, eOperandType type) {this->_list = new std::list< Stack >;};
        ~OperatorC() {};
        
    private :
        bool exit = false;
        static int  const precision = 8;
        std::list< Stack > *_list;
};

#endif