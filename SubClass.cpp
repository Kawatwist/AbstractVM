/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SubClass.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <lomasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 18:00:19 by lomasse           #+#    #+#             */
/*   Updated: 2020/10/17 17:10:38 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Includes/FactoryOperator.Class.hpp"
#include "./Includes/TypeOperator.Class.hpp"
#include "./Includes/MasterOperator.Class.hpp"

extern FactoryOperator Factory;
extern MasterOperator Manager;

IOperand const *FactoryOperator::CreateType( std::string type, std::string value)
{
	if (!type.compare("int8"))
		return (FactoryOperator::createInt8(value));
	else if (!type.compare("int16"))
		return (FactoryOperator::createInt16(value));
	else if (!type.compare("int32"))
		return (FactoryOperator::createInt32(value));
	else if (!type.compare("float"))
		return (FactoryOperator::createFloat(value));
	return (FactoryOperator::createDouble(value));
}

IOperand const *FactoryOperator::CreateType( eOperandType type, std::string value)
{
	if (type == eOperandType::Int8)
		return (FactoryOperator::createInt8(value));
	else if (type == eOperandType::Int16)
		return (FactoryOperator::createInt16(value));
	else if (type == eOperandType::Int32)
		return (FactoryOperator::createInt32(value));
	else if (type == eOperandType::Float)
		return (FactoryOperator::createFloat(value));
	return (FactoryOperator::createDouble(value));
}


IOperand const* FactoryOperator::createInt8( std::string const   & value ) const
{
	/* Checking value */
	return (new class Int8(std::stoi(value)));
}

IOperand const* FactoryOperator::createInt16( std::string const  & value ) const
{
	/* Checking value */
	return (new class Int16(std::stoi(value)));
}

IOperand const* FactoryOperator::createInt32( std::string const  & value ) const
{
	/* Checking value */
	return (new class Int32(std::stoi(value)));
}

IOperand const* FactoryOperator::createFloat( std::string const  & value ) const
{
	/* Checking value */
	return (new class Float(std::stof(value)));
}

IOperand const* FactoryOperator::createDouble( std::string const & value ) const
{
	/* Checking value */
	return (new class Double(std::stod(value)));
}

/*
**	Exception
*/

bool		MasterOperator::HasBeenExit(void)		const
{
	return (this->exited); // Exit ?
}

void		MasterOperator::CanOperate(void)
{
	if (this->_list.size() < 2)
		throw MasterOperator::StackException(ArithmeticError);	
}

/*
**  get Function
*/

std::string const & FormalizeType::toString(void)	const
{
	std::string const *a = new std::string("toString ?");
	return (*a);
}

int			 FormalizeType::getPrecision(void)  	const
{
	return (8);
}

eOperandType    FormalizeType::getType(void) const
{
	return (eOperandType::Int8);
}


/*
**  IOperand Function
*/

IOperand const *FormalizeType::operator+( IOperand const& rhs ) const
{
	eOperandType type = (this->getType() > rhs.getType() ? this->getType() : rhs.getType());
	std::ostringstream adds;
	adds << (std::stod(this->toString()) + std::stod(rhs.toString()));
	return (Factory.CreateType(type, adds.str()));
}	

IOperand const *FormalizeType::operator-( IOperand const& rhs ) const
{
	eOperandType type = (this->getType() > rhs.getType() ? this->getType() : rhs.getType());
	std::ostringstream adds;
	adds << (std::stod(this->toString()) - std::stod(rhs.toString()));
	return (Factory.CreateType(type, adds.str()));
}

IOperand const *FormalizeType::operator*( IOperand const& rhs ) const
{
	eOperandType type = (this->getType() > rhs.getType() ? this->getType() : rhs.getType());
	std::ostringstream adds;
	adds << (std::stod(this->toString()) * std::stod(rhs.toString()));
	return (Factory.CreateType(type, adds.str()));
}

IOperand const *FormalizeType::operator/( IOperand const& rhs ) const
{
	eOperandType type = (this->getType() > rhs.getType() ? this->getType() : rhs.getType());
	std::ostringstream adds;
	if (std::stod(rhs.toString()) == 0)
		throw MasterOperator::StackException(ByZero);
	adds << (std::stod(this->toString()) / std::stod(rhs.toString()));
	return (Factory.CreateType(type, adds.str()));
}

IOperand const *FormalizeType::operator%( IOperand const& rhs ) const
{
	eOperandType type = (this->getType() > rhs.getType() ? this->getType() : rhs.getType());
	std::ostringstream adds;
	if (std::stod(rhs.toString()) == 0)
		throw MasterOperator::StackException(ByZero);
	adds << (std::stod(this->toString()) - (std::stod(this->toString()) / std::stod(rhs.toString())));
	std::cout << "Modulo :" << (std::stod(this->toString()) - (std::stod(this->toString()) / std::stod(rhs.toString()))) << std::endl;
	return (Factory.CreateType(type, adds.str()));
}
