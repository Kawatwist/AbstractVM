/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <lomasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 21:24:27 by lomasse           #+#    #+#             */
/*   Updated: 2020/10/17 17:17:27 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Includes/MasterOperator.Class.hpp"
#include "./Includes/TypeOperator.Class.hpp"
#include "./Includes/FactoryOperator.Class.hpp"

FactoryOperator Factory;
MasterOperator Manager;

int main(int argc, char **argv)
{
    try
    {
        Manager.OP_push(Factory.CreateType(std::string("int8"), std::string("5")));
        Manager.OP_push(Factory.CreateType(std::string("float"), std::string("4.35")));
        Manager.OP_assert(Factory.CreateType(std::string("float"), std::string("4.35")));
        Manager.OP_add();
        Manager.OP_push(Factory.CreateType(std::string("int8"), std::string("4")));
        Manager.OP_mod();
        Manager.OP_dump();
        // Manager.OP_exit();
        if (Manager.HasBeenExit() == false)
            throw MasterOperator::StackException(NoExit);
    }
    catch (std::exception & e)
    {
        std::cout << "Exception Occurs : " << e.what() << std::endl;
    }
    return (0);
}