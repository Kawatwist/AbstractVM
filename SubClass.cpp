/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SubClass.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <lomasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 18:00:19 by lomasse           #+#    #+#             */
/*   Updated: 2020/10/19 15:29:29 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Includes/FactoryOperator.Class.hpp"
#include "./Includes/TypeOperator.Class.hpp"
#include "./Includes/MasterOperator.Class.hpp"
#include <limits>
#include <map>

extern FactoryOperator Factory;

IOperand const* FactoryOperator::createOperand( eOperandType type, std::string const & value ) const
{
	switch (type)
	{
		case Int8 :
			return (FactoryOperator::createInt8(value));
		case Int16 :
			return (FactoryOperator::createInt16(value));
		case Int32 :
			return (FactoryOperator::createInt32(value));
		case Float :
			return (FactoryOperator::createFloat(value));
		default :
			return (FactoryOperator::createDouble(value));
	}
}

eOperandType    FactoryOperator::convertType(std::string type) const
{
	static const char *tab[] = {"int8", "int16", "int32", "float", "double"};
	
    for (size_t i = 0; i < sizeof(tab) / sizeof(tab[0]); i++)
    {
        if (strcmp(type.c_str(), tab[i]) == 0)
            return (static_cast<eOperandType>(i));
    }
    return (eOperandType::Double);
}

IOperand const* FactoryOperator::createInt8( std::string const   & value ) const
{
	try { std::stoi(value); }
	catch (std::exception &)
		{ throw MasterOperator::StackException(OverFlow); }
	if (std::stol(value) < std::numeric_limits<int8_t>::min())
		throw MasterOperator::StackException(UnderFlow);
	if (std::stol(value) > std::numeric_limits<int8_t>::max())
		throw MasterOperator::StackException(OverFlow);
	return (new class Int8(std::stoi(value)));
}

IOperand const* FactoryOperator::createInt16( std::string const  & value ) const
{
	try { std::stoi(value); }
	catch (std::exception &)
		{ throw MasterOperator::StackException(OverFlow); }
	if (std::stol(value) < std::numeric_limits<int16_t>::min())
		throw MasterOperator::StackException(UnderFlow);
	if (std::stol(value) > std::numeric_limits<int16_t>::max())
		throw MasterOperator::StackException(OverFlow);
	return (new class Int16(std::stoi(value)));
}

IOperand const* FactoryOperator::createInt32( std::string const  & value ) const
{
	try { std::stoi(value); }
	catch (std::exception &)
		{ throw MasterOperator::StackException(OverFlow); }
	if (std::stol(value) < std::numeric_limits<int32_t>::min())
		throw MasterOperator::StackException(UnderFlow);
	if (std::stol(value) > std::numeric_limits<int32_t>::max())
		throw MasterOperator::StackException(OverFlow);
	return (new class Int32(std::stoi(value)));
}

IOperand const* FactoryOperator::createFloat( std::string const  & value ) const
{
	try { std::stof(value); }
	catch (std::exception &)
		{ throw MasterOperator::StackException(OverFlow); }
	if (std::stold(value) < std::numeric_limits<float>::min())
		throw MasterOperator::StackException(UnderFlow);
	if (std::stold(value) > std::numeric_limits<float>::max())
		throw MasterOperator::StackException(OverFlow);
	return (new class Float(std::stof(value)));
}

IOperand const* FactoryOperator::createDouble( std::string const & value ) const
{
	try { std::stod(value); }
	catch (std::exception &)
		{ throw MasterOperator::StackException(OverFlow); }
	if (std::stold(value) < std::numeric_limits<double>::min())
		throw MasterOperator::StackException(UnderFlow);
	if (std::stold(value) > std::numeric_limits<double>::max())
		throw MasterOperator::StackException(OverFlow);
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
	return (Factory.createOperand(type, adds.str()));
}	

IOperand const *FormalizeType::operator-( IOperand const& rhs ) const
{
	eOperandType type = (this->getType() > rhs.getType() ? this->getType() : rhs.getType());
	std::ostringstream adds;
	adds << (std::stod(this->toString()) - std::stod(rhs.toString()));
	return (Factory.createOperand(type, adds.str()));
}

IOperand const *FormalizeType::operator*( IOperand const& rhs ) const
{
	eOperandType type = (this->getType() > rhs.getType() ? this->getType() : rhs.getType());
	std::ostringstream adds;
	adds << (std::stod(this->toString()) * std::stod(rhs.toString()));
	return (Factory.createOperand(type, adds.str()));
}

IOperand const *FormalizeType::operator/( IOperand const& rhs ) const
{
	eOperandType type = (this->getType() > rhs.getType() ? this->getType() : rhs.getType());
	std::ostringstream adds;
	if (std::stod(rhs.toString()) == 0)
		throw MasterOperator::StackException(ByZero);
	adds << (std::stod(this->toString()) / std::stod(rhs.toString()));
	return (Factory.createOperand(type, adds.str()));
}

IOperand const *FormalizeType::operator%( IOperand const& rhs ) const
{
	eOperandType type = (this->getType() > rhs.getType() ? this->getType() : rhs.getType());
	std::ostringstream adds;
	if (std::stod(rhs.toString()) == 0)
		throw MasterOperator::StackException(ByZero);
	adds << (std::stod(this->toString()) - (std::stod(this->toString()) / std::stod(rhs.toString())));
	return (Factory.createOperand(type, adds.str()));
}
