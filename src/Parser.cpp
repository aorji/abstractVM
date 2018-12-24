/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 10:52:46 by aorji             #+#    #+#             */
/*   Updated: 2018/12/24 10:52:51 by aorji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Parser.hpp"

Parser::Parser() {
    checker["int8"] = &Parser::check_int8;
    checker["int16"] = &Parser::check_int16;
    checker["int32"] = &Parser::check_int32;
    checker["float"] = &Parser::check_float;
    checker["double"] = &Parser::check_double;
}

Parser::~Parser() = default;

void
Parser::run(std::vector<std::map<std::string, std::string>> data) {
    for (auto &v: data)
        if (v["cmd"] == "push" || v["cmd"] == "assert")
            (this->*checker[v["type"]])(v["value"]);
}

void
Parser::check_int8( std::string value ) {
    int result = 0;
    try {
        result = stoi(value);
    } catch (std::exception &e) {
        throw RangeError("int8(" + value + ")");
    }
    if (result < std::numeric_limits<signed char>::min() ||
        result > std::numeric_limits<signed char>::max())
        throw RangeError("int8(" + value + ")");
}

void
Parser::check_int16( std::string value ){
    int result = 0;
    try {
        result = stoi(value);
    } catch (std::exception &e) {
        throw RangeError("int16(" + value + ")");
    }
    if (result < std::numeric_limits<short>::min() ||
        result > std::numeric_limits<short>::max())
        throw RangeError("int16(" + value + ")");
};

void
Parser::check_int32( std::string value ){
    try {
        stoi(value);
    } catch (std::exception &e) {
        throw RangeError("int32(" + value + ")");
    }
};

void
Parser::check_float( std::string value ){
    try {
        stof(value);
    } catch (std::exception &e) {
        throw RangeError("float(" + value + ")");
    }
};

void
Parser::check_double( std::string value ){
    try {
        stod(value);
    } catch (std::exception &e) {
        throw RangeError("double(" + value + ")");
    }
};

