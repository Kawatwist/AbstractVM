/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   Stack.Class.cpp									:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: lomasse <lomasse@student.42.fr>			+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2020/10/13 21:54:47 by lomasse		   #+#	#+#			 */
/*   Updated: 2020/10/14 19:18:22 by lomasse		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "Stack.Class.hpp"

bool		OperatorC::HasBeenExit(void)		const
{
	return (this->exit);
}

void        Stack::setType(eOperandType type)
{
	this->_type = type;
}

template < typename T >
void        Stack::setValue(T value)
{
	if (std::is_same<T, int8_t>::value)
	{
		this->_content = value;
	}
}

Stack		OperatorC::toType(std::string type, std::string value) const
{
	if (type.compare("int8"))
		return (Stack ret(OP_INT8, std::stoi(value)));
	else if (type.compare("int16"))
		return (Stack ret(OP_INT16, std::stoi(value)));
	else if (type.compare("int32"))
		return (Stack ret(OP_INT32, std::stoi(value)));
	else if (type.compare("float"))
		return (Stack ret(OP_FLOAT, std::stoi(value)));
	return (Stack ret(OP_DOUBLE, std::stoi(value)));
}

void		Stack::print_content(void)			const
{
	std::cout << "Type " << this->getType() << std::endl;
	std::cout << "Value : " << (static_cast<int>(this->_content)) << std::endl; 
}

void		OperatorC::CanOperate(void)
{
	if (this->_list->size() < 2)
		throw OperatorC::StackException(ArithmeticError);	
}

/*
**  get Function
*/

std::string const & OperatorC::toString(void)	const
{
	std::string const *a = new std::string("toString ?");
	return (*a);
}

int			 OperatorC::getPrecision(void)  	const
{
	return (this->precision);
}

eOperandType	OperatorC::getType(void)		const
{
	return (OP_INT8);
}

eOperandType	Stack::getType(void)			const
{
	return (this->_type);
}

/*
**  IOperand Function
*/

IOperand const *OperatorC::operator+( IOperand const& rhs ) const
{
	return (&rhs);
}

IOperand const *OperatorC::operator-( IOperand const& rhs ) const
{
	return (&rhs);
}

IOperand const *OperatorC::operator*( IOperand const& rhs ) const
{
	return (&rhs);
}

IOperand const *OperatorC::operator/( IOperand const& rhs ) const
{
	return (&rhs);
}

IOperand const *OperatorC::operator%( IOperand const& rhs ) const
{
	return (&rhs);
}
