/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FactoryOperator.Class.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <lomasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 13:47:58 by lomasse           #+#    #+#             */
/*   Updated: 2020/10/17 16:54:25 by lomasse          ###   ########.fr       */
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
        IOperand const* CreateType( std::string type, std::string value);
        IOperand const* CreateType( eOperandType type, std::string value);

        IOperand const* createInt8( std::string const   & value ) const;
        IOperand const* createInt16( std::string const  & value ) const;
        IOperand const* createInt32( std::string const  & value ) const;
        IOperand const* createFloat( std::string const  & value ) const;
        IOperand const* createDouble( std::string const & value ) const;
        
};

#endif