//
// Created by Anastasiia ORJI on 12/22/18.
//

#ifndef _EXECUTOR_HPP
#define _EXECUTOR_HPP

#include <vector>
#include <map>
#include <iostream>
#include "Exception.hpp"
#include "IOperand.hpp"
#include "Factory.hpp"

class Executor {
public:
    Executor();
	Executor( Executor const & src );
    ~Executor();

   void pop( );
   void dump( );
   void add( );
   void sub( );
   void mul( );
   void div( );
   void mod( );
   void print( );
   void exit( );
   void push( std::string type, std::string value );
   void assert( std::string value);

   void run( std::vector<std::map<std::string, std::string>> data);

	Executor & operator=( Executor const & rhs);
private:
	bool exit_;
	std::vector<IOperand const *> stack;
    std::map<std::string, void (Executor::*)()> instruction;
};

#endif
