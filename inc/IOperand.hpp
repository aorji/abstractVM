//
// Created by Anastasiia ORJI on 13/12/2018.
//
#ifndef I_OPERAND_HPP
#define I_OPERAND_HPP

#include <string>
#include <vector>
#include <iostream>
#include <string>

//New operands created via a "factory method".

// AbstractVM uses 5 operand classes:
// • Int8   : Representation of a signed integer coded on 8bits.
// • Int16  : Representation of a signed integer coded on 16bits.
// • Int32  : Representation of a signed integer coded on 32bits.
// • Float  : Representation of a float.
// • Double : Representation of a double.

enum eOperandType {
    Int8,
    Int16,
    Int32,
    Float,
    Double
};

class IOperand {

public:

	virtual int getPrecision( void ) const = 0; // Precision of the type of the instance
  	virtual eOperandType getType( void ) const = 0; // Type of the instance

//	virtual IOperand const * operator+( IOperand const & rhs ) const = 0; // Sum
//	virtual IOperand const * operator-( IOperand const & rhs ) const = 0; // Difference
//	virtual IOperand const * operator*( IOperand const & rhs ) const = 0; // Product
//	virtual IOperand const * operator/( IOperand const & rhs ) const = 0; // Quotient
//	virtual IOperand const * operator%( IOperand const & rhs ) const = 0; // Modulo

	virtual std::string const & toString( void ) const = 0; // String representation of the instance

    virtual ~IOperand( void ) {}
};

#endif

