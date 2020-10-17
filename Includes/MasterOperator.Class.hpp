/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MasterOperator.Class.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <lomasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 15:38:33 by lomasse           #+#    #+#             */
/*   Updated: 2020/10/17 17:25:47 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MASTEROPERATOR_CLASS_HPP
# define MASTEROPERATOR_CLASS_HPP

#include "IOperand.Class.hpp"
#include <list>
#include <limits>
#include <maps>

std::maps function;

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

class MasterOperator
{
    public :    
        void		    CanOperate(void);
        bool		    HasBeenExit(void)		const;

        /* Opcode */
        void            OP_push(const IOperand* toPush);
        void            OP_pop(const IOperand*);
        void            OP_dump(const IOperand*);
        void            OP_assert(const IOperand* toCmp);
        void            OP_add(const IOperand*);
        void            OP_sub(const IOperand*);
        void            OP_mul(const IOperand*);
        void            OP_div(const IOperand*);
        void            OP_mod(const IOperand*);
        void            OP_print(const IOperand*);
        void            OP_exit(const IOperand*);
        
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
    private :
        bool                        exited = false;
        std::list<IOperand const *> _list;
};

#endif