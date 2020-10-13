/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stack.Class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <lomasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 21:54:47 by lomasse           #+#    #+#             */
/*   Updated: 2020/10/13 22:06:32 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Stack.Class.hpp"

/*
**  IOperand Function
*/


template< typename T >
int             Stack<T>::getPrecision(void)  const
{
    return (0);
}

template< typename T >
eOperandType    Stack<T>::getType(void)       const
{
    return (OP_INT8);
}


template< typename T >
IOperand const *Stack<T>::operator+( IOperand const& rhs ) const
{
    return (&rhs);
}

template< typename T >
IOperand const *Stack<T>::operator-( IOperand const& rhs ) const
{
    return (&rhs);
}

template< typename T >
IOperand const *Stack<T>::operator*( IOperand const& rhs ) const
{
    return (&rhs);
}

template< typename T >
IOperand const *Stack<T>::operator/( IOperand const& rhs ) const
{
    return (&rhs);
}

template< typename T >
IOperand const *Stack<T>::operator%( IOperand const& rhs ) const
{
    return (&rhs);
}
