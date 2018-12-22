//
// Created by Anastasiia ORJI on 12/22/18.
//

#include "../inc/Parser.hpp"

Parser::Parser() {
    checker.push_back(&Parser::check_int8); //at(0)
    checker.push_back(&Parser::check_int16);
    checker.push_back(&Parser::check_int32);
    checker.push_back(&Parser::check_float);
    checker.push_back(&Parser::check_double); //at(4)
}

Parser::~Parser() {}

void
Parser::syntactic_analysis(std::vector<std::map<std::string, std::string>> data) {
    for (auto &v: data) {
        if (v["cmd"] == "push" || v["cmd"] == "assert") {
            if (v["type"] == "int8")
                (this->*checker.at(0))(v["value"]);
            else if (v["type"] == "int16")
                (this->*checker.at(1))(v["value"]);
            else if (v["type"] == "int32")
                (this->*checker.at(2))(v["value"]);
            else if (v["type"] == "float")
                (this->*checker.at(3))(v["value"]);
            else if (v["type"] == "double")
                (this->*checker.at(4))(v["value"]);
        }
    }
}

void
Parser::check_int8( std::string value ) {
//    int result = 0;
//    try {
//        result = stoi(value);
//        if (result < std::numeric_limits<signed char >::min() ||
//            result > std::numeric_limits<signed char>::max()){
//            throw RangeError(value);
//        }
//    } catch (std::exception &e) {
//        throw RangeError(value);
//    }
}

void
Parser::check_int16( std::string value ){
//    int result = 0;
//    try {
//        result = stoi(value);
//        if (result < std::numeric_limits<short >::min() ||
//            result > std::numeric_limits<short>::max())
//            throw RangeError(value);
//    } catch (std::exception &e) {
//        throw RangeError(value);
//    }
};

void
Parser::check_int32( std::string value ){
    try {
        stoi(value);
    } catch (std::exception &e) {
        throw RangeError(value);
    }
};

void
Parser::check_float( std::string value ){
    try {
        stof(value);
    } catch (std::exception &e) {
        throw RangeError(value);
    }
};

void
Parser::check_double( std::string value ){
    try {
        stod(value);
    } catch (std::exception &e) {
        throw RangeError(value);
    }
};

