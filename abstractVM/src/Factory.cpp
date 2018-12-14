//
// Created by Anastasiia ORJI on 13/12/2018.
//

#include "../inc/Factory.hpp"

IOperand const * 
Factory::createOperand( eOperandType type, std::string const & value ) const {
    // switch(type)
    // {
    //     case Int8:
    //     	return createInt8(value);
    //     case Int16:
    //     	return createInt16(value);
    //     case Int32:
    //     	return createInt32(value);
    //     case Float:
    //     	return createFloat(value);
    //     case Double:
    //     	return createIntDouble(value);
    //     default:
    //     	return NULL;
    // }
}

IOperand const *
Factory::createInt8( std::string const & value ) const { return new Operand<int8_t>(value); }

IOperand const * 
Factory::createInt16( std::string const & value ) const { return new Operand<int16_t>(value); }

IOperand const * 
Factory::createInt32( std::string const & value ) const { return new Operand<int32_t>(value); }

IOperand const * 
Factory::createFloat( std::string const & value ) const { return new Operand<float>(value); }

IOperand const * 
Factory::createDouble( std::string const & value ) const { return new Operand<double>(value); }