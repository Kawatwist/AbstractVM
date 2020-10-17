/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Operator.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <lomasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 15:59:22 by lomasse           #+#    #+#             */
/*   Updated: 2020/10/17 17:10:57 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Includes/MasterOperator.Class.hpp"
#include "./Includes/FactoryOperator.Class.hpp"

extern FactoryOperator Factory;
extern MasterOperator Manager;

void            MasterOperator::OP_push(const IOperand* toPush)
{
    this->_list.emplace_front(toPush);
}

void            MasterOperator::OP_pop(void)
{
    if (this->_list.empty() == true)
        throw (MasterOperator::StackException(EmptyStack));
    this->_list.pop_front();
}

void            MasterOperator::OP_dump(void) const
{
    for (auto i : this->_list)
        std::cout << i->getType() << " <= " << i->toString() << std::endl;
}

void            MasterOperator::OP_assert(const IOperand* toCmp)
{
    if (this->_list.empty() == true)
        throw (MasterOperator::StackException(EmptyStack));
    this->_list.begin();
    auto current = this->_list.front();
    if (toCmp->toString().compare(current->toString()))
        throw (MasterOperator::StackException(AssertNotTrue));
}

void            MasterOperator::OP_add(void)
{
    this->CanOperate();
    const IOperand* v1 = this->_list.front();
    this->_list.pop_front();
    const IOperand* v2 = this->_list.front();
    this->_list.pop_front();
    std::cout << v1->toString() << std::endl;
    std::cout << v2->toString() << std::endl;
	IOperand* r = const_cast<IOperand*>(*v2 + *v1);
    this->OP_push(r);
}

void            MasterOperator::OP_sub(void)
{
    this->CanOperate();
    const IOperand* v1 = this->_list.front();
    this->_list.pop_front();
    const IOperand* v2 = this->_list.front();
    this->_list.pop_front();
    std::cout << v1->toString() << std::endl;
    std::cout << v2->toString() << std::endl;
	IOperand* r = const_cast<IOperand*>(*v2 - *v1);
    this->OP_push(r);
}

void            MasterOperator::OP_mul(void)
{
    this->CanOperate();
    const IOperand* v1 = this->_list.front();
    this->_list.pop_front();
    const IOperand* v2 = this->_list.front();
    this->_list.pop_front();
    std::cout << v1->toString() << std::endl;
    std::cout << v2->toString() << std::endl;
	IOperand* r = const_cast<IOperand*>(*v2 * *v1);
    this->OP_push(r);
}

void            MasterOperator::OP_div(void)
{
    this->CanOperate();
    const IOperand* v1 = this->_list.front();
    this->_list.pop_front();
    const IOperand* v2 = this->_list.front();
    this->_list.pop_front();
    std::cout << v1->toString() << std::endl;
    std::cout << v2->toString() << std::endl;
	IOperand* r = const_cast<IOperand*>(*v2 / *v1);
    this->OP_push(r);
}

void            MasterOperator::OP_mod(void)
{
    this->CanOperate();
    const IOperand* v1 = this->_list.front();
    this->_list.pop_front();
    const IOperand* v2 = this->_list.front();
    this->_list.pop_front();
    std::cout << v1->toString() << std::endl;
    std::cout << v2->toString() << std::endl;
	IOperand* r = const_cast<IOperand*>(*v2 % *v1);
    this->OP_push(r);
}

void            MasterOperator::OP_print(void)
{
    if (this->_list.empty() == true)
        throw (MasterOperator::StackException(EmptyStack));
    auto current = this->_list.front();
    std::cout << current->getType() << " <= " << current->toString() << std::endl;
}

void            MasterOperator::OP_exit(void)
{
    this->exited = true;
}
