//
// Created by Anastasiia ORJI on 12/14/18.
//

#include "Operand.hpp"

Operand::Operand(std::string const &value): dataStr_(value) { }

Operand::~Operand() { }

int
Operand::getPrecision( void ) const { return precision_; }

eOperandType
Operand::getType( void ) const { return type_; }

std::string
Operand::const & toString( void ) const { return dataStr_; }