//
// Created by Anastasiia ORJI on 13/12/2018.
//

#ifndef EXEPTION_HPP
#define EXEPTION_HPP

#include <exception>

class DivisionByZero: public std::exception {
public:
    DivisionByZero( );
    DivisionByZero( DivisionByZero const & src );
    ~DivisionByZero( ) throw();
    DivisionByZero & operator=( DivisionByZero const & rhs);
    const char* what() const throw();
};

#endif