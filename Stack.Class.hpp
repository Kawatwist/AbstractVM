/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stack.Class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <lomasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 21:28:41 by lomasse           #+#    #+#             */
/*   Updated: 2020/10/13 22:03:03 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_CLASS
# define STACK_CLASS

#include <stack>
#include "IOperand.Class.hpp"

enum eOperandType { OP_INT8, OP_INT16, OP_INT32, OP_FLOAT, OP_DOUBLE };

template< typename T>
class Stack : public IOperand
{
    public:
        void    OP_push(int n);
        void    OP_pop(void);
        void    OP_dump(void) const;
        void    OP_assert(int n);
        void    OP_add(void);
        void    OP_sub(void);
        void    OP_mul(void);
        void    OP_div(void);
        void    OP_mod(void);
        void    OP_print(void);
        void    OP_exit(void);

        Stack() : _content(NULL), _next(NULL) {};
        ~Stack() {delete this->_content;};
        
        class StackException : public std::exception
        {
            public :
                virtual const char * what() const throw() {return ("StackException");};
        };
        
        int             getPrecision(void)  const;
        eOperandType    getType(void)       const;
        
        IOperand const *operator+( IOperand const& rhs ) const;
        IOperand const *operator-( IOperand const& rhs ) const;
        IOperand const *operator*( IOperand const& rhs ) const;
        IOperand const *operator/( IOperand const& rhs ) const;
        IOperand const *operator%( IOperand const& rhs ) const;
        
    private:
        T * _content;
        Stack<T> * _next;
};

#endif