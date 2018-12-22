//
// Created by Anastasiia ORJI on 13/12/2018.
//

#ifndef EXEPTION_HPP
#define EXEPTION_HPP

#include <exception>
#include <string>

class DivisionByZero: public std::exception {
public:
    explicit DivisionByZero( std::string lhs, std::string rhs );
    DivisionByZero( DivisionByZero const & src );
    ~DivisionByZero( ) throw();
    DivisionByZero & operator=( DivisionByZero const & rhs);
    const char* what() const throw();

private:
    std::string rhs_;
    std::string lhs_;
};

class LexerError: public std::exception {
public:
    explicit LexerError( std::string error );
    LexerError( LexerError const & src );
    ~LexerError( ) throw();
    LexerError & operator=( LexerError const & rhs);
    const char* what() const throw();

private:
    std::string error_line;
};

#endif