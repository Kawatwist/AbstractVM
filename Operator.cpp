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

extern FactoryOperator Factory;
extern MasterOperator Manager;

void           OP_push(const IOperand* toPush)
{
    Manager._list.emplace_front(toPush);
    // delete toPush;
}

void           OP_pop(const IOperand*)
{
    if (Manager._list.empty() == true)
        throw (MasterOperator::StackException(EmptyStack));
    Manager._list.pop_front();
}

void           OP_dump(const IOperand*)
{
    for (auto i : Manager._list)
        std::cout << i->getType() << " <= " << i->toString() << std::endl;
}

void           OP_assert(const IOperand* toCmp)
{
    if (Manager._list.empty() == true)
        throw (MasterOperator::StackException(EmptyStack));
    Manager._list.begin();
    auto current = Manager._list.front();
    if (toCmp->toString().compare(current->toString()))
        throw (MasterOperator::StackException(AssertNotTrue));
    // delete toCmp;
}

void           OP_add(const IOperand*)
{
    Manager.CanOperate();
    const IOperand* v1 = Manager._list.front();
    Manager._list.pop_front();
    const IOperand* v2 = Manager._list.front();
    Manager._list.pop_front();
    std::cout << v1->toString() << std::endl;
    std::cout << v2->toString() << std::endl;
	IOperand* r = const_cast<IOperand*>(*v2 + *v1);
    OP_push(r);
}

void           OP_sub(const IOperand*)
{
    Manager.CanOperate();
    const IOperand* v1 = Manager._list.front();
    Manager._list.pop_front();
    const IOperand* v2 = Manager._list.front();
    Manager._list.pop_front();
    std::cout << v1->toString() << std::endl;
    std::cout << v2->toString() << std::endl;
	IOperand* r = const_cast<IOperand*>(*v2 - *v1);
    OP_push(r);
}

void           OP_mul(const IOperand*)
{
    Manager.CanOperate();
    const IOperand* v1 = Manager._list.front();
    Manager._list.pop_front();
    const IOperand* v2 = Manager._list.front();
    Manager._list.pop_front();
    std::cout << v1->toString() << std::endl;
    std::cout << v2->toString() << std::endl;
	IOperand* r = const_cast<IOperand*>(*v2 * *v1);
    OP_push(r);
}

void           OP_div(const IOperand*)
{
    Manager.CanOperate();
    const IOperand* v1 = Manager._list.front();
    Manager._list.pop_front();
    const IOperand* v2 = Manager._list.front();
    Manager._list.pop_front();
    std::cout << v1->toString() << std::endl;
    std::cout << v2->toString() << std::endl;
	IOperand* r = const_cast<IOperand*>(*v2 / *v1);
    OP_push(r);
}

void           OP_mod(const IOperand*)
{
    Manager.CanOperate();
    const IOperand* v1 = Manager._list.front();
    Manager._list.pop_front();
    const IOperand* v2 = Manager._list.front();
    Manager._list.pop_front();
    std::cout << v1->toString() << std::endl;
    std::cout << v2->toString() << std::endl;
	IOperand* r = const_cast<IOperand*>(*v2 % *v1);
    OP_push(r);
}

void           OP_print(const IOperand*)
{
    if (Manager._list.empty() == true)
        throw (MasterOperator::StackException(EmptyStack));
    auto current = Manager._list.front();
    std::cout << current->getType() << " <= " << current->toString() << std::endl;
}

void           OP_exit(const IOperand*)
{
    Manager.exited = true;
}
