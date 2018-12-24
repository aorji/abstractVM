/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 10:54:20 by aorji             #+#    #+#             */
/*   Updated: 2018/12/24 10:54:27 by aorji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
    Parser( Parser const & src );
    ~Parser();

    void run(std::vector<std::map<std::string, std::string>> data);
    void check_int8( std::string value );
    void check_int16( std::string value );
    void check_int32( std::string value );
    void check_float( std::string value );
    void check_double( std::string value );

    Parser & operator=( Parser const & rhs);
private:
    std::map<std::string, void (Parser::*)( std::string )> checker;
};

#endif
