//
// Created by Anastasiia ORJI on 13/12/2018.
//
#ifndef OPERAND_HPP
#define OPERAND_HPP

#include "IOperand.hpp"

template <typename T>

class Operand: public IOperand {
//
public:

    Operand( std::string const & value ):
            dataStr_(value) {}

	int getPrecision( void ) const { // Precision of the type of the instance
        return this->precision_;
	}
	eOperandType getType( void ) const { return this->type_; } // Type of the instance

//	IOperand const * operator+( IOperand const & rhs ) const; // Sum
//	IOperand const * operator-( IOperand const & rhs ) const; // Difference
//	IOperand const * operator*( IOperand const & rhs ) const; // Product
//	IOperand const * operator/( IOperand const & rhs ) const; // Quotient
//	IOperand const * operator%( IOperand const & rhs ) const; // Modulo

	std::string const & toString( void ) const{ return this->dataStr_; } // String representation of the instance

	virtual ~Operand( void ){};

private:
    T               data_;
    std::string     dataStr_;
    eOperandType    type_;
    int             precision_;
};

#endif
