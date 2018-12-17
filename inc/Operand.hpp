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
            dataStr_(value) {
        setPrecision();
        setType();
    }

	int getPrecision( void ) const { // Precision of the type of the instance
        return this->precision_;
	}
	eOperandType getType( void ) const { return this->type_; } // Type of the instance

    void setPrecision() {
        size_t point = dataStr_.find(".");
        if (point != std::string::npos)
            precision_ = dataStr_.length() - point - 1;
        else
            precision_ = 0;
    }

    void setType() {
        if (std::is_same<T, signed char>::value)
            type_ = Int8;
        else if (std::is_same<T, short>::value)
            type_ = Int16;
        else if (std::is_same<T, int>::value)
            type_ = Int32;
        else if (std::is_same<T, float>::value)
            type_ = Float;
        else if (std::is_same<T, double>::value)
            type_ = Double;
        //else error
    }
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
    size_t          precision_;
};

#endif
