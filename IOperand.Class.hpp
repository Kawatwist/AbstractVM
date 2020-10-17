#ifndef IOPERAND_HPP
# define IOPERAND_HPP

#include <string>
#include <list>
#include <iostream>

enum eOperandType { Int8Class, Int16Class , Int32Class , FloatClass, DoubleClass};

class IOperand {
    public:
        virtual int             getPrecision(void)const= 0;
        virtual eOperandType    getType(void) const= 0;
        
        virtual IOperand const *operator+( IOperand const& rhs ) const= 0;
        virtual IOperand const *operator-( IOperand const& rhs ) const= 0;
        virtual IOperand const *operator*( IOperand const& rhs ) const= 0;
        virtual IOperand const *operator/( IOperand const& rhs ) const= 0;
        virtual IOperand const *operator%( IOperand const& rhs ) const= 0;
        
        virtual std::string const & toString(void) const= 0;
        
        ~IOperand(void) {}
};

#endif