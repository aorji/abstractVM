//
// Created by Anastasiia ORJI on 13/12/2018.
//
#include <iostream>
#include "../inc/Lexer.hpp"
#include "../inc/Operand.hpp"
#include "../inc/Parser.hpp"
#include "../inc/Executor.hpp"
//#include "../inc/Factory.hpp"

int main(int ac, char **av) {
//    eOperandType type = Float;
//    Factory creator;
//    IOperand const *a = creator.createOperand(type, "5");
//    IOperand const *b = creator.createOperand(type, "0");
//    std::cout << "string: " << a->toString() << std::endl;
//    std::cout << "precision: " << a->getPrecision() << std::endl;
//    std::cout << "type: " << a->getType() << std::endl;
//    std::cout << "a + b = " << (*a + *b)->toString() << std::endl;
//    std::cout << "a - b = " << (*a - *b)->toString() << std::endl;
//    std::cout << "a * b = " << (*a * *b)->toString() << std::endl;
//    std::cout << "a / b = " << (*a / *b)->toString() << std::endl;
//    std::cout << "a % b = " << (*a % *b)->toString() << std::endl;
//    ac = 0;
//    av = NULL;
//        for(auto & v: result)
//            if (v["cmd"] != "")
//                std::cout << "cmd: " << v["cmd"] << std::endl;
    try {
        Lexer lexer(ac, av);
        lexer.run();
        std::vector<std::map<std::string, std::string>> result = lexer.getReadValue();
        Parser parser;
        parser.syntactic_analysis(result);
        Executor executor;
        executor.run(result);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }


}
