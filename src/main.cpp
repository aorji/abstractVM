//
// Created by Anastasiia ORJI on 13/12/2018.
//
#include <iostream>
#include <Factory.hpp>

#include "../inc/Operand.hpp"
//#include "../inc/Factory.hpp"

int main(){
    eOperandType type = Int16;
    Factory creator;
    IOperand const *a = creator.createOperand(type, "13");
    std::cout << "string: " << a->toString() << std::endl;
    std::cout << "precision: " << a->getPrecision() << std::endl;
    std::cout << "type: " << a->getType() << std::endl;
//    std::cout << "in T: " << a->getData() << std::endl;
}
