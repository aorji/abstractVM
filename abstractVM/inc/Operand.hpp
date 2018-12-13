#ifndef OPERAND_HPP
#define OPERAND_HPP

#include "IOperand.hpp"
#include <string>

template <typename T>

class Operand: public IOperand {

public:

//    int getPrecision( void ) const = 0; // Precision of the type of the instance
    eOperandType getType( void ) const = 0; // Type of the instance
//
//    IOperand const * operator+( IOperand const & rhs ) const = 0; // Sum
//    IOperand const * operator-( IOperand const & rhs ) const = 0; // Difference
//    IOperand const * operator*( IOperand const & rhs ) const = 0; // Product
//    IOperand const * operator/( IOperand const & rhs ) const = 0; // Quotient
//    IOperand const * operator%( IOperand const & rhs ) const = 0; // Modulo
//
//    std::string const & toString( void ) const = 0; // String representation of the instance

    virtual ~Operand( void ) {}
};

#endif
