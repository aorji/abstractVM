//
// Created by Anastasiia ORJI on 12/14/18.
//

#include "../inc/Operand.hpp"

Operand::Operand( std::string const & value, eOperandType type, int precision ):
    dataStr_(value),
    type_(type),
    precision_(precision){

    try {
        data_ = std::stod(value);
    }
    catch (std::exception &e) {}
    std::cout << e.what() << std::endl;

}

Operand::~Operand() { }

int
Operand::getPrecision( void ) const { return precision_; }

eOperandType
Operand::getType( void ) const { return type_; }

std::string
Operand::const & toString( void ) const { return dataStr_; }