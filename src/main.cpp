//
// Created by Anastasiia ORJI on 13/12/2018.
//
#include <iostream>
#include <Factory.hpp>

#include "../inc/Operand.hpp"
//#include "../inc/Factory.hpp"

int main(){
    std::cout << "Hello" << std::endl;
    eOperandType type = Int16;
    Factory creator;
    IOperand const *a = creator.createOperand(type, "13");
    std::cout << a->toString() << std::endl;
    std::cout << a->getPrecision() << std::endl;
    std::cout << a->getType() << std::endl;}
