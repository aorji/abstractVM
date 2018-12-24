//
// Created by Anastasiia ORJI on 13/12/2018.
//
#include <iostream>
#include "../inc/Lexer.hpp"
#include "../inc/Operand.hpp"
#include "../inc/Parser.hpp"
#include "../inc/Executor.hpp"

int main(int ac, char **av) {
    try {
        Lexer lexer(ac, av);
        lexer.run();
        std::vector<std::map<std::string, std::string>> result = lexer.getReadValue();

        Parser parser;
        parser.run(result);

        Executor executor;
        executor.run(result);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }


}
