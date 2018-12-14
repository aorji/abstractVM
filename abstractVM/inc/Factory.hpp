#ifndef FACTORY_HPP
#define FACTORY_HPP

#include "Operand.hpp"
#include <string>
#include <cstdint>

class Factory {

public:
	Factory( eOperandType type, std::string const & value ){
		ptrOperand = IOperand::createOperand(type, value);
	}
    static IOperand const * createOperand( eOperandType type, std::string const & value ) const;

private:
    IOperand const * createInt8( std::string const & value ) const;
    IOperand const * createInt16( std::string const & value ) const;
    IOperand const * createInt32( std::string const & value ) const;
    IOperand const * createFloat( std::string const & value ) const;
    IOperand const * createDouble( std::string const & value ) const;

    IOperand *ptrOperand;

};

#endif