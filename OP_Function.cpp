/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OP_Function.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <lomasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 16:20:40 by lomasse           #+#    #+#             */
/*   Updated: 2020/10/15 15:30:33 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Stack.Class.hpp"

void    OperatorC::OP_push(Stack toPush)
{
    this->_list->emplace_front(toPush);
}

void    OperatorC::OP_push(std::string type, std::string value)
{
    this->_list->emplace_front(static_cast< Stack >(Stack(type, value)));
}

void    OperatorC::OP_pop(void)
{
    if (this->_list->empty() == true)
        throw OperatorC::StackException(EmptyStack);
    this->_list->pop_front();
}

void    OperatorC::OP_dump(void) const
{
    for (Stack i : *(this->_list))
        i.print_content();
}

void    OperatorC::OP_assert(std::string type, std::string value)
{
    Stack A = this->_list->front();
    if (A.getValue<std::string>() != value)
        throw OperatorC::StackException(AssertNotTrue);
}

Stack   

void    OperatorC::OP_add(void)
{
    this->CanOperate();
    this->_list->begin();

    Stack & v1 = this->_list->front();
    this->_list->pop_front();
    Stack & v2 = this->_list->front();
    this->_list->pop_front();

    this->OP_push()
}

void    OperatorC::OP_sub(void)
{
    this->CanOperate();
    this->_list->begin();
    
    Stack & v1 = this->_list->front();
    this->_list->pop_front();

    Stack & v2 = this->_list->front();
    this->_list->pop_front();
}

void    OperatorC::OP_mul(void)
{
    this->CanOperate();
    this->_list->begin();
    
    Stack & v1 = this->_list->front();
    this->_list->pop_front();

    Stack & v2 = this->_list->front();
    this->_list->pop_front();
    
}

void    OperatorC::OP_div(void)
{
    this->CanOperate();
    this->_list->begin();
    
    Stack & v1 = this->_list->front();
    this->_list->pop_front();

    Stack & v2 = this->_list->front();
    this->_list->pop_front();
    
    if (B == 0)
        throw OperatorC::StackException(ByZero);
    
}

void    OperatorC::OP_mod(void)
{
    this->CanOperate();
    this->_list->begin();
    
    Stack & v1 = this->_list->front();
    this->_list->pop_front();

    Stack & v2 = this->_list->front();
    this->_list->pop_front();
    
    if (B == 0)
        throw OperatorC::StackException(ByZero);
}

void    OperatorC::OP_print(void)
{
    if (this->_list->empty() == true)
        throw OperatorC::StackException(EmptyStack);
    Stack a = this->_list->front();
    a.print_content();
}

void    OperatorC::OP_exit(void)
{
    this->exit = true;
}
