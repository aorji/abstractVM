/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Operand.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 10:54:09 by aorji             #+#    #+#             */
/*   Updated: 2018/12/24 10:54:15 by aorji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
    }

    Operand ( Operand const & src ) { *this = src; }

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
    }

//    getters

	int getPrecision( ) const override { // Precision of the type of the instance
        return this->precision_;
	}

	eOperandType getType( ) const override { return this->type_; } // Type of the instance

	IOperand const * operator+( IOperand const & rhs ) const override { // Sum
        std::ostringstream ss;
        eOperandType newOperandType = (this->type_ >= rhs.getType()) ? this->type_ : rhs.getType();
        switch (newOperandType) {
            case 0:
            case 1:
            case 2:
                try {
                    ss << stoi(this->dataStr_) + stoi(rhs.toString());
                } catch (std::exception &e) {
                    std::cout << e.what() << std::endl;
                }
                break;
            case 3:
                try {
                    ss << stof(this->dataStr_) + stof(rhs.toString());
                } catch (std::exception &e) {
                    std::cout << e.what() << std::endl;
                }
                break;
            case 4:
                try {
                    ss << stod(this->dataStr_) + stod(rhs.toString());
                } catch (std::exception &e) {
                    std::cout << e.what() << std::endl;
                }
        }
        return Factory().createOperand(newOperandType, ss.str());
    }

	IOperand const * operator-( IOperand const & rhs ) const override { // Difference
        std::ostringstream ss;
        eOperandType newOperandType = (this->type_ >= rhs.getType()) ? this->type_ : rhs.getType();
        switch (newOperandType) {
            case 0:
            case 1:
            case 2:
                try {
                    ss << stoi(this->dataStr_) - stoi(rhs.toString());
                } catch (std::exception &e) {
                    std::cout << e.what() << std::endl;
                }
                break;
            case 3:
                try {
                    ss << stof(this->dataStr_) - stof(rhs.toString());
                } catch (std::exception &e) {
                    std::cout << e.what() << std::endl;
                }
                break;
            case 4:
                try {
                    ss << stod(this->dataStr_) - stod(rhs.toString());
                } catch (std::exception &e) {
                    std::cout << e.what() << std::endl;
                }
        }
        return Factory().createOperand(newOperandType, ss.str());
    }

    IOperand const * operator*( IOperand const & rhs ) const override {
        std::ostringstream ss;
        eOperandType newOperandType = (this->type_ >= rhs.getType()) ? this->type_ : rhs.getType();
        switch (newOperandType) {
            case 0:
            case 1:
            case 2:
                try {
                    ss << stoi(this->dataStr_) * stoi(rhs.toString());
                } catch (std::exception &e) {
                    std::cout << e.what() << std::endl;
                }
                break;
            case 3:
                try {
                    ss << stof(this->dataStr_) * stof(rhs.toString());
                } catch (std::exception &e) {
                    std::cout << e.what() << std::endl;
                }
                break;
            case 4:
                try {
                    ss << stod(this->dataStr_) * stod(rhs.toString());
                } catch (std::exception &e) {
                    std::cout << e.what() << std::endl;
                }
        }
        return Factory().createOperand(newOperandType, ss.str());
    }

    IOperand const * operator/( IOperand const & rhs ) const override {
        std::ostringstream ss;
        eOperandType newOperandType = (this->type_ >= rhs.getType()) ? this->type_ : rhs.getType();
        switch (newOperandType) {
            case 0:
            case 1:
            case 2:
                if (!stoi(rhs.toString()))
                    throw DivisionByZero(toString(), rhs.toString());
                try {
                    ss << stoi(this->dataStr_) / stoi(rhs.toString());
                } catch (std::exception &e) {
                    std::cout << e.what() << std::endl;
                }
                break;
            case 3:
                if (!stof(rhs.toString()))
                    throw DivisionByZero(toString(), rhs.toString());
                try {
                    ss << stof(this->dataStr_) / stof(rhs.toString());
                } catch (std::exception &e) {
                    std::cout << e.what() << std::endl;
                }
                break;
            case 4:
                if (!stod(rhs.toString()))
                    throw DivisionByZero(toString(), rhs.toString());
                try {
                    ss << stod(this->dataStr_) / stod(rhs.toString());
                } catch (std::exception &e) {
                    std::cout << e.what() << std::endl;
                }
        }
        return Factory().createOperand(newOperandType, ss.str());
    }

    IOperand const * operator%( IOperand const & rhs ) const override {
        std::ostringstream ss;
        eOperandType newOperandType = (this->type_ >= rhs.getType()) ? this->type_ : rhs.getType();
        switch (newOperandType) {
            case 0:
            case 1:
            case 2:
                if (!stoi(rhs.toString()))
                    throw DivisionByZero(toString(), rhs.toString());
                try {
                    ss << stoi(this->dataStr_) % stoi(rhs.toString());
                } catch (std::exception &e) {
                    std::cout << e.what() << std::endl;
                }
                break;
            case 3:
                if (!stof(rhs.toString()))
                    throw DivisionByZero(toString(), rhs.toString());
                try {
                    ss << fmod(stof(this->dataStr_), stof(rhs.toString()));
                } catch (std::exception &e) {
                    std::cout << e.what() << std::endl;
                }
                break;
            case 4:
                if (!stod(rhs.toString()))
                    throw DivisionByZero(toString(), rhs.toString());
                try {
                    ss << fmod(stod(this->dataStr_), stod(rhs.toString()));
                } catch (std::exception &e) {
                    std::cout << e.what() << std::endl;
                }
        }
        return Factory().createOperand(newOperandType, ss.str());
    }

	std::string const & toString( ) const override { return this->dataStr_; } // String representation of the instance

    Operand & operator=( Operand const & rhs) {
        (void)rhs;
        return *this;
    }

	virtual ~Operand( ) {};

private:
    std::string     dataStr_;
    eOperandType    type_;
    int             precision_;
};

#endif
