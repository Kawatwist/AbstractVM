/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Type.Class.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <lomasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 15:33:43 by lomasse           #+#    #+#             */
/*   Updated: 2020/10/15 18:01:35 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPECLASS_HPP
# define TYPECLASS_HPP

#include "Operator.Class.hpp"
#include <limits>

template <typename T>
class SubClass
{
    private :
        eOperandType    op;
        T               var;
};

class Int8Class
{
    public :
        int8_t getValue(void) const;
        
        Int8Class(std::string value)
            {/*if (std::stoi(value, 0, 10) > std::numeric_limits<char>::max()) throw Operator::StackException(OverFlow);*/ this->value = std::stoi(value, 0, 10);};
        ~Int8Class() {};
        
    private : 
        int8_t value;
};

class Int16Class
{
    public :
        int16_t getValue(void) const;
        
    private : 
        int16_t value;
};

class Int32Class
{
    public :
        int32_t getValue(void) const;
        
    private : 
        int32_t value;
};

class FloatClass
{
    public :
        float getValue(void) const;
        
    private : 
        float value;
};

class DoubleClass
{
    public :
        double getValue(void) const;
        
    private : 
        double value;
};

#endif