/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Operator.Class.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <lomasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 15:38:33 by lomasse           #+#    #+#             */
/*   Updated: 2020/10/15 18:00:48 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATOR_CLASS_HPP
# define OPERATOR_CLASS_HPP

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

class Operand : public IOperand
{
    public :
        void            print_content(void) const;
        int             getPrecision(void)      const;
        eOperandType    getType(void)           const;
        std::string const & toString(void)      const;
        
        /* Operator */
        IOperand const *operator+( IOperand const & rhs ) const;
        IOperand const *operator-( IOperand const & rhs ) const;
        IOperand const *operator*( IOperand const & rhs ) const;
        IOperand const *operator/( IOperand const & rhs ) const;
        IOperand const *operator%( IOperand const & rhs ) const;
};

class MasterOperator
{
    private :
        std::list<Operand>     _list;
    public :    
        void		    CanOperate(void);
        bool		    HasBeenExit(void)		const;

        /* Opcode */
        void            OP_push(std::string type, std::string value);
        void            OP_pop(void);
        void            OP_dump(void) const;
        void            OP_assert(std::string type, std::string value);
        void            OP_add(void);
        void            OP_sub(void);
        void            OP_mul(void);
        void            OP_div(void);
        void            OP_mod(void);
        void            OP_print(void);
        void            OP_exit(void);

        
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
};

#endif