/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SubClass.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <lomasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 18:00:19 by lomasse           #+#    #+#             */
/*   Updated: 2020/10/15 18:00:21 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Operator.Class.hpp"
#include "Type.Class.hpp"

/*
**	Exception
*/

bool		MasterOperator::HasBeenExit(void)		const
{
	return (true); // Exit ?
}

void		MasterOperator::CanOperate(void)
{
	if (this->_list.size() < 2)
		throw MasterOperator::StackException(ArithmeticError);	
}

/*
**  get Function
*/

std::string const & Operand::toString(void)	const
{
	std::string const *a = new std::string("toString ?");
	return (*a);
}

int			 Operand::getPrecision(void)  	const
{
	return (8);
}

eOperandType    Operand::getType(void) const
{
	return (Int8Class);
}


/*
**  IOperand Function
*/

IOperand const *Operand::operator+( IOperand const& rhs ) const
{
	return (&rhs);
}

IOperand const *Operand::operator-( IOperand const& rhs ) const
{
	return (&rhs);
}

IOperand const *Operand::operator*( IOperand const& rhs ) const
{
	return (&rhs);
}

IOperand const *Operand::operator/( IOperand const& rhs ) const
{
	return (&rhs);
}

IOperand const *Operand::operator%( IOperand const& rhs ) const
{
	return (&rhs);
}
