/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TypeOperator.Class.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <lomasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 13:58:42 by lomasse           #+#    #+#             */
/*   Updated: 2020/10/17 19:37:16 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPEOPERATOR_HPP
# define TYPEOPERATOR_HPP

#include "IOperand.Class.hpp"
#include <iostream>
#include <sstream>

class   FormalizeType : public IOperand
{
    
    public:
        int            getPrecision(void)      const;
        eOperandType   getType(void)           const;
        /* Operator overload */
        IOperand const *operator+( IOperand const & rhs ) const;
        IOperand const *operator-( IOperand const & rhs ) const;
        IOperand const *operator*( IOperand const & rhs ) const;
        IOperand const *operator/( IOperand const & rhs ) const;
        IOperand const *operator%( IOperand const & rhs ) const;
        std::string const &     toString(void)      const;
};

class   Int8 : public FormalizeType
{
    public :
        Int8(int8_t Value) : value(Value) {std::ostringstream convert; convert << static_cast<int>(value); this->Svalue = convert.str();};
        ~Int8() {};
        eOperandType    getType(void) const {return (eOperandType::Int8);};
        std::string const & toString(void)      const {return (this->Svalue);};
    protected :
        int8_t          value;
        eOperandType    Type;
        std::string     Svalue;
};

class   Int16 : public FormalizeType
{
    public :
        Int16(int16_t Value) : value(Value) {std::ostringstream convert; convert << value;this->Svalue = convert.str();};
        ~Int16() {};
        eOperandType    getType(void) const {return (eOperandType::Int16);};
        std::string const & toString(void)      const {return (this->Svalue);};
    protected :
        int16_t         value;
        eOperandType    Type;
        std::string     Svalue;
};

class   Int32 : public FormalizeType
{
    public :
        Int32(int32_t Value) : value(Value) {std::ostringstream convert; convert << value;this->Svalue = convert.str();};
        ~Int32() {};
        eOperandType    getType(void) const {return (eOperandType::Int32);};
        std::string const & toString(void)      const {return (this->Svalue);};
    protected :
        int32_t         value;
        eOperandType    Type;
        std::string     Svalue;
};

class   Float : public FormalizeType
{
    public :
        Float(float Value) : value(Value) {std::ostringstream convert; convert << value;this->Svalue = convert.str();};
        ~Float() {};
        eOperandType    getType(void) const {return (eOperandType::Float);};
        std::string const & toString(void)      const {return (this->Svalue);};
    protected :
        float           value;
        eOperandType    Type;
        std::string     Svalue;
};

class   Double : public FormalizeType
{
    public :
        Double(double Value) : value(Value) {std::ostringstream convert; convert << value;this->Svalue = convert.str();};
        ~Double() {};
        eOperandType    getType(void) const {return (eOperandType::Double);};
        std::string const & toString(void)      const {return (this->Svalue);};
    protected :
        double          value;
        eOperandType    Type;
        std::string     Svalue;
};

#endif