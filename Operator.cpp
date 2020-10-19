/* ************************************************************************** */
/*                                                                            */
/*                                                       :     ::::::   */
/*   Operator.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <lomasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 15:59:22 by lomasse           #+#    #+#             */
/*   Updated: 2020/10/17 17:55:08 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Includes/MasterOperator.Class.hpp"
#include "./Includes/FactoryOperator.Class.hpp"
#include "./Includes/TypeOperator.Class.hpp"
#include <iomanip>

extern FactoryOperator Factory;
extern MasterOperator Manager;
extern int  c_flg;

void           OP_push(const IOperand* toPush)
{
    Manager._list.emplace_front(toPush);
}

void           OP_pop(const IOperand*)
{
    if (Manager._list.empty() == true)
        throw (MasterOperator::StackException(EmptyStack));
    const IOperand* v1 = Manager._list.front();
    if (c_flg)
        std::cout << GREEN << "Removing " << v1->toString() << WHITE << std::endl;
    Manager._list.pop_front();
    delete v1;
}

void           OP_dump(const IOperand*)
{
    for (auto i : Manager._list)
        std::cout << i->toString() << std::endl;
}

void           OP_assert(const IOperand* toCmp)
{
    if (Manager._list.empty() == true)
        throw (MasterOperator::StackException(EmptyStack));
    Manager._list.begin();
    auto current = Manager._list.front();
    if (toCmp->toString().compare(current->toString()) && toCmp->getType() == current->getType())
        throw (MasterOperator::StackException(AssertNotTrue));
}

void           OP_add(const IOperand*)
{
    Manager.CanOperate();
    const IOperand* v1 = Manager._list.front();
    Manager._list.pop_front();
    const IOperand* v2 = Manager._list.front();
    Manager._list.pop_front();
	IOperand* r = const_cast<IOperand*>(*v2 + *v1);
    OP_push(r);
    if (c_flg)
        std::cout << GREEN << v2->toString() << " + "<< v1->toString() << " = " << r->toString() << WHITE << std::endl;
    delete v1;
    delete v2;
}

void           OP_sub(const IOperand*)
{
    Manager.CanOperate();
    const IOperand* v1 = Manager._list.front();
    Manager._list.pop_front();
    const IOperand* v2 = Manager._list.front();
    Manager._list.pop_front();
	IOperand* r = const_cast<IOperand*>(*v2 - *v1);
    OP_push(r);
    if (c_flg)
        std::cout << GREEN << v2->toString() << " - " << v1->toString() << " = " << r->toString() << WHITE << std::endl;
    delete v1;
    delete v2;
}

void           OP_mul(const IOperand*)
{
    Manager.CanOperate();
    const IOperand* v1 = Manager._list.front();
    Manager._list.pop_front();
    const IOperand* v2 = Manager._list.front();
    Manager._list.pop_front();
	IOperand* r = const_cast<IOperand*>(*v2 * *v1);
    OP_push(r);
    if (c_flg)
        std::cout << GREEN << v2->toString() << " * " << v1->toString() << " = " << r->toString() << WHITE << std::endl;
    delete v1;
    delete v2;
}

void           OP_div(const IOperand*)
{
    Manager.CanOperate();
    const IOperand* v1 = Manager._list.front();
    Manager._list.pop_front();
    const IOperand* v2 = Manager._list.front();
    Manager._list.pop_front();
	IOperand* r = const_cast<IOperand*>(*v2 / *v1);
    OP_push(r);
    if (c_flg)
        std::cout << GREEN << v2->toString() << " / " << v1->toString() << " = " << r->toString() << WHITE << std::endl;
    delete v1;
    delete v2;
}

void           OP_mod(const IOperand*)
{
    Manager.CanOperate();
    const IOperand* v1 = Manager._list.front();
    Manager._list.pop_front();
    const IOperand* v2 = Manager._list.front();
    Manager._list.pop_front();
	IOperand* r = const_cast<IOperand*>(*v2 % *v1);
    OP_push(r);
    if (c_flg)
        std::cout << GREEN << v2->toString() << " % " << v1->toString() << " = " << r->toString() << WHITE << std::endl;
    delete v1;
    delete v2;
}

void           OP_printf(const IOperand*)
{
    if (Manager._list.empty() == true)
        throw (MasterOperator::StackException(EmptyStack));
    auto current = Manager._list.front();
    if (current->getType() >= Float)
    {
        std::cout << std::setprecision(current->getPrecision()) << std::stof(current->toString());
        if (c_flg)
            std::cout << std::endl;
    }
    else
        throw (MasterOperator::StackException(PrintNonFloat));
}

void           OP_print(const IOperand*)
{
    if (Manager._list.empty() == true)
        throw (MasterOperator::StackException(EmptyStack));
    auto current = Manager._list.front();
    if (current->getType() == Int8)
    {
        std::cout << static_cast<char>(std::stoi(current->toString()));
        if (c_flg)
            std::cout << std::endl;
    }
    else
        throw (MasterOperator::StackException(PrintNonAscii));
}

void           OP_exit(const IOperand*)
{
    Manager.exited = true;
}
