//
// Created by Anastasiia ORJI on 13/12/2018.
//
#include <iostream>
#include <Factory.hpp>

#include "../inc/Operand.hpp"
//#include "../inc/Factory.hpp"

int main(){
    eOperandType type = Float;
    Factory creator;
    IOperand const *a = creator.createOperand(type, "10");
    IOperand const *b = creator.createOperand(type, "5");
    std::cout << "string: " << a->toString() << std::endl;
    std::cout << "precision: " << a->getPrecision() << std::endl;
    std::cout << "type: " << a->getType() << std::endl;
    std::cout << "a + b = " << (*a + *b)->toString() << std::endl;
    std::cout << "a - b = " << (*a - *b)->toString() << std::endl;
    std::cout << "a * b = " << (*a * *b)->toString() << std::endl;
    std::cout << "a / b = " << (*a / *b)->toString() << std::endl;
    std::cout << "a % b = " << (*a % *b)->toString() << std::endl;
}
