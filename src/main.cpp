//
// Created by Anastasiia ORJI on 13/12/2018.
//
#include <iostream>
#include <Factory.hpp>
#include "Lexer.hpp"
#include "../inc/Operand.hpp"
#include "../inc/Parser.hpp"
//#include "../inc/Factory.hpp"

int main(int ac, char **av) {
//    while (1){
//        std::string line;
//        std::getline(std::cin, line);
//        std::regex instr_with_no_value("^(pop|dump|add|sub|mul|div|mod|print|exit)");
//        std::regex instr_with_int_value(R"(^(push|assert)\s+(int8|int16|int32)(\()([\-]?\d+)(\)))");
//        std::regex instr_with_fd_value(R"(^(push|assert)\s+(float|double)(\()([\-]?\d+\.\d+)(\)))");
//        std::smatch result;
//        if (std::regex_match(line, result,  instr_with_no_value) || std::regex_match(line, result, instr_with_int_value) || std::regex_match(line, result, instr_with_fd_value))
//        {   std::cout << result[1] << std::endl;
//            std::cout << result[2] << std::endl;
//            std::cout << result[3] << std::endl;
//            std::cout << result[4] << std::endl;
//            std::cout << result[5] << std::endl;
//            if (result[3] == "")
//                std::cout << "---------------";
//        }
//        else
//            std::cout << "-" << std::endl;
//        if (line == "ex")
//            break;
//
//    }
//    std::cout << ac << " " << av[0];
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
    try {
        Lexer lexer(ac, av);
        lexer.run();
        std::vector<std::map<std::string, std::string>> result = lexer.getReadValue();
        for(auto & v: result)
            if (v["cmd"] != "")
                std::cout << "cmd: " << v["cmd"] << std::endl;
        Parser parser = Parser();
        parser.syntactic_analysis(result);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

}
