//
// Created by Anastasiia ORJI on 13/12/2018.
//
#ifndef FACTORY_HPP
#define FACTORY_HPP

#include "Operand.hpp"
#include <string>
#include <cstdint>

class Factory {

public:
    Factory();
    ~Factory();
    IOperand const * createOperand( eOperandType type, std::string const & value ) const;

private:
    IOperand const * createInt8( std::string const & value ) const;
    IOperand const * createInt16( std::string const & value ) const;
    IOperand const * createInt32( std::string const & value ) const;
    IOperand const * createFloat( std::string const & value ) const;
    IOperand const * createDouble( std::string const & value ) const;

    std::vector<IOperand const* (Factory::*)( std::string const & ) const> creator;

};

#endif