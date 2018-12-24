//
// Created by Anastasiia ORJI on 12/22/18.
//

#ifndef PARSER_HPP
#define PARSER_HPP

#include <string>
#include <vector>
#include <map>
#include <limits>
#include <iostream>

#include <Exception.hpp>

class Parser {

public:
    Parser();
    ~Parser();

    void run(std::vector<std::map<std::string, std::string>> data);
    void check_int8( std::string value );
    void check_int16( std::string value );
    void check_int32( std::string value );
    void check_float( std::string value );
    void check_double( std::string value );

private:
    std::vector<void (Parser::*)( std::string )> checker;
};

#endif
