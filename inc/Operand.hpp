//
// Created by Anastasiia ORJI on 13/12/2018.
//
#ifndef OPERAND_HPP
#define OPERAND_HPP

//#include "IOperand.hpp"
#include "Factory.hpp"

template <typename T>

class Operand: public IOperand {

public:

    Operand( ): dataStr_("0"), precision_(0), type_(Int8) {}

    explicit Operand( std::string const & value ):
            dataStr_(value) {
        setPrecision();
        setType();
//        setData();
    }

//    setters
    void setPrecision() {
        size_t point = dataStr_.find(".");
        (point != std::string::npos) ? precision_ = dataStr_.length() - point - 1 : precision_ = 0;
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

//    getters

	int getPrecision( ) const override { // Precision of the type of the instance
        return this->precision_;
	}
	eOperandType getType( ) const override { return this->type_; } // Type of the instance

	IOperand const * operator+( IOperand const & rhs ) const override {
        if (this->type_ >= rhs.getType()) {
            T result = 0;
            std::ostringstream ss;
            switch (this->type_) {
                case 0:
                case 1:
                case 2:
                    try {
                        result = stoi(this->dataStr_) + stoi(rhs.toString());
                    } catch (std::exception &e) {
                        std::cout << e.what() << std::endl;
                    }
                case 3:
                    try {
                        result = stof(this->dataStr_) + stoi(rhs.toString());
                    } catch (std::exception &e) {
                        std::cout << e.what() << std::endl;
                    }
                case 4:
                    try {
                        result = stod(this->dataStr_);
                    } catch (std::exception &e) {
                        std::cout << e.what() << std::endl;
                    }
            }
            ss << result;
            return Factory().createOperand(this->type_, ss.str());
        }
        return Factory().createOperand(this->type_, "to replase");
//        else
    } // Sum
//	IOperand const * operator-( IOperand const & rhs ) const; // Difference
//	IOperand const * operator*( IOperand const & rhs ) const; // Product
//	IOperand const * operator/( IOperand const & rhs ) const; // Quotient
//	IOperand const * operator%( IOperand const & rhs ) const; // Modulo

	std::string const & toString( ) const override { return this->dataStr_; } // String representation of the instance

	virtual ~Operand( ) {};

private:
    std::string     dataStr_;
    eOperandType    type_;
    int          precision_;
};

#endif
