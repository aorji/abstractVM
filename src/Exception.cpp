//
// Created by Anastasiia ORJI on 13/12/2018.
//

#include "../inc/Exception.hpp"

DivisionByZero::DivisionByZero ( ) {}
DivisionByZero::DivisionByZero ( DivisionByZero const & src ) { *this = src; }
DivisionByZero::~DivisionByZero ( ) throw() {}
DivisionByZero &
DivisionByZero::operator=( DivisionByZero::DivisionByZero const & rhs) {
	(void)rhs;
	return *this;
}
const char *
DivisionByZero::what() const throw() { return ("Error: Divisor is equal to 0!"); }