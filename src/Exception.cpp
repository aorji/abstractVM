/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Exception.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 10:47:28 by aorji             #+#    #+#             */
/*   Updated: 2018/12/24 10:49:40 by aorji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Exception.hpp"
#include <iostream>

DivisionByZero::DivisionByZero ( std::string lhs, std::string rhs ): rhs_(rhs), lhs_(lhs) {}
DivisionByZero::DivisionByZero ( DivisionByZero const & src ) { *this = src; }
DivisionByZero::~DivisionByZero ( ) throw() {}
DivisionByZero &
DivisionByZero::operator=( DivisionByZero const & rhs) {
	(void)rhs;
	return *this;
}
const char *
DivisionByZero::what() const throw() {
	std::string division_error = "Error in \"" + lhs_ + " / " + rhs_ + "\": Divisor is equal to 0!\"";
	return division_error.c_str();
}

LexerError::LexerError ( std::string error ): error_line(error) {}
LexerError::LexerError ( LexerError const & src ) { *this = src; }
LexerError::~LexerError ( ) throw() {}
LexerError &
LexerError::operator=( LexerError const & rhs) {
	(void)rhs;
	return *this;
}
const char *
LexerError::what() const throw() {
    return error_line.c_str();
}

RangeError::RangeError ( std::string error ): error_line(error) {}
RangeError::RangeError ( RangeError const & src ) { *this = src; }
RangeError::~RangeError ( ) throw() {}
RangeError &
RangeError::operator=( RangeError const & rhs) {
    (void)rhs;
    return *this;
}
const char *
RangeError::what() const throw() {
    std::string range_error = "Error: \"" + error_line +  "\" is out of range";
    return range_error.c_str();
}

StackError::StackError ( std::string error ): error_line(error) {}
StackError::StackError ( StackError const & src ) { *this = src; }
StackError::~StackError ( ) throw() {}
StackError &
StackError::operator=( StackError const & rhs) {
    (void)rhs;
    return *this;
}
const char *
StackError::what() const throw() {
    return error_line.c_str();
}

FileAccess::FileAccess ( char* error ): error_line(error) {}
FileAccess::FileAccess ( FileAccess const & src ) { *this = src; }
FileAccess::~FileAccess ( ) throw() {}
FileAccess &
FileAccess::operator=( FileAccess const & rhs) {
    (void)rhs;
    return *this;
}
const char *
FileAccess::what() const throw() {
    const char *access_line = "Bad file access";
    return access_line;
}
