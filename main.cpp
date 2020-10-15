/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <lomasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 21:24:27 by lomasse           #+#    #+#             */
/*   Updated: 2020/10/15 18:01:58 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Operator.Class.hpp"

#include <list>

void    randpush(std::list<std::string> & type, std::list<std::string> & value)
{
    char tab[5][7] = {"int8", "int16", "int32", "float", "double"};
    
    type.push_front(tab[rand() % 5]);
    value.push_front("42");
}

int main(int argc, char **argv)
{
    std::list<std::string> type;
    std::list<std::string> value;
    
    for (int i=0; i < 10; i++)
        randpush(type, value);
        
    MasterOperator oper;
    try
    {
        for (int i=0; i < 10; i++)
            oper.OP_push(type.front(), value.front());

        // oper.OP_push(OP_INT8, 33);
        // oper.OP_add();
        // oper.OP_push(OP_FLOAT, 44.55);
        // oper.OP_mul();
        // oper.OP_push(OP_FLOAT, 42.42);
        // oper.OP_push(OP_INT8, 42);
        // oper.OP_dump();
        // oper.OP_pop();
        // oper.OP_assert(OP_FLOAT, 42.42);
        
        oper.OP_exit();
        
        if (oper.HasBeenExit() == false)
            throw MasterOperator::StackException(NoExit);
    }
    catch (std::exception & e)
    {
        std::cout << "Exception Occurs : " << e.what() << std::endl;
    }
    return (0);
}