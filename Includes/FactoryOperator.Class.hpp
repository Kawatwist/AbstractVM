/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FactoryOperator.Class.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <lomasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 13:47:58 by lomasse           #+#    #+#             */
/*   Updated: 2020/10/19 15:01:57 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FactoryOperator_HPP
# define FactoryOperator_HPP

#include "IOperand.Class.hpp"
#include "TypeOperator.Class.hpp"

class FactoryOperator : public FormalizeType
{
    public:
        
        /* Type Creator */
        IOperand const* createOperand( eOperandType type, std::string const & value )const;
        eOperandType    convertType(std::string type) const;

        IOperand const* createInt8( std::string const   & value ) const;
        IOperand const* createInt16( std::string const  & value ) const;
        IOperand const* createInt32( std::string const  & value ) const;
        IOperand const* createFloat( std::string const  & value ) const;
        IOperand const* createDouble( std::string const & value ) const;
        
};

#endif