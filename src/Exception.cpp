//
// Created by Anastasiia ORJI on 13/12/2018.
//

#include "../inc/Exception.hpp"

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
    std::string lexer_error = "Lexer Error in \"" + error_line +  "\"";
    return lexer_error.c_str();
}