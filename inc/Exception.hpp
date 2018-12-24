/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Exception.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 10:53:21 by aorji             #+#    #+#             */
/*   Updated: 2018/12/24 10:53:27 by aorji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
    const char* what() const throw() override;

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
    const char* what() const throw() override;

private:
    std::string error_line;
};

class RangeError: public std::exception {
public:
    explicit RangeError( std::string error );
    RangeError( RangeError const & src );
    ~RangeError( ) throw();
    RangeError & operator=( RangeError const & rhs);
    const char* what() const throw() override;

private:
    std::string error_line;
};

class StackError: public std::exception {
public:
    explicit StackError( std::string error );
    StackError( StackError const & src );
    ~StackError( ) throw();
    StackError & operator=( StackError const & rhs);
    const char* what() const throw() override;

private:
    std::string error_line;
};

class FileAccess: public std::exception {
public:
    explicit FileAccess( char *error );
    FileAccess( FileAccess const & src );
    ~FileAccess( ) throw();
    FileAccess & operator=( FileAccess const & rhs);
    const char* what() const throw() override;

private:
    std::string error_line;
};

#endif
