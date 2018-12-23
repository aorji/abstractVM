//
// Created by Anastasiia ORJI on 13/12/2018.
//
#include <iostream>
#include "../inc/Lexer.hpp"
#include "../inc/Operand.hpp"
#include "../inc/Parser.hpp"
#include "../inc/Executor.hpp"
// #include <algorithm>
//#include "../inc/Factory.hpp"

int main(int ac, char **av) {
    try {
        Lexer lexer(ac, av);
        lexer.run();
        std::vector<std::map<std::string, std::string>> result = lexer.getReadValue();
        Parser parser;
        parser.syntactic_analysis(result);
        // std::reverse(result.begin(),result.end());
        // for(auto & v: result)
        //     std::cout << v["cmd"] << std::endl;
        Executor executor;
        executor.run(result);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }


}
