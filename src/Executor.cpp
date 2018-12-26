/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Executor.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 10:51:33 by aorji             #+#    #+#             */
/*   Updated: 2018/12/24 10:51:40 by aorji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Executor.hpp"

Executor::Executor(): exit_(false) {
	instruction["pop"] = &Executor::pop;
    instruction["dump"] = &Executor::dump;
	instruction["add"] = &Executor::add;
	instruction["sub"] = &Executor::sub;
	instruction["mul"] = &Executor::mul;
	instruction["div"] = &Executor::div;
	instruction["mod"] = &Executor::mod;
	instruction["print"] = &Executor::print;
	instruction["exit"] = &Executor::exit;
}

Executor::~Executor() = default;

Executor::Executor ( Executor const & src ) { *this = src; }

std::vector<std::map<std::string, std::string>>::iterator
Executor::run(std::vector<std::map<std::string, std::string>>::iterator it) {
    while (1){
		if ((*it)["cmd"] == "exit"){
		    reset();
			return ++it;
		}
		if ((*it)["cmd"] != "push" && (*it)["cmd"] != "assert" && !(*it)["cmd"].empty())
			(this->*instruction[(*it)["cmd"]])();
		if ((*it)["cmd"] == "push")
		 	push((*it)["type"], (*it)["value"]);
		else if ((*it)["cmd"] == "assert")
			assert((*it)["type"], (*it)["value"]);
		++it;
	}
}

void
Executor::pop( ) {
   if (stack.empty())
       throw StackError("Error: empty stack");
   IOperand const *a = stack.back();
   stack.pop_back();
   delete a;
}

void
Executor::dump( ) {
   for(auto it = stack.rbegin(); it != stack.rend(); ++it)
    	std::cout << (*it)->toString() << std::endl;
}

void
Executor::add( ) {
	if (stack.size() < 2) {
        reset();
		throw StackError("Error: missing operand");
	}
	IOperand const *a = stack.back();
	pop();
	IOperand const *b = stack.back();
	pop();
	stack.push_back(*a + *b);
	delete a;
    delete b;
}

void
Executor::sub( ) {
	if (stack.size() < 2) {
        reset();
		throw StackError("Error: missing operand");
	}
	IOperand const *a = stack.back();
	pop();
	IOperand const *b = stack.back();
	pop();
	stack.push_back(*b - *a);
    delete a;
    delete b;
}

void
Executor::mul( ) {
	if (stack.size() < 2) {
        reset();
		throw StackError("Error: missing operand");
	}
	IOperand const *a = stack.back();
	pop();
	IOperand const *b = stack.back();
	pop();
	stack.push_back(*a * *b);
    delete a;
    delete b;
}

void
Executor::div( ) {
	if (stack.size() < 2) {
        reset();
		throw StackError("Error: missing operand");
	}
	IOperand const *a = stack.back();
	pop();
	IOperand const *b = stack.back();
	pop();
	stack.push_back(*b / *a);
    delete a;
    delete b;
}

void
Executor::mod( ) {
	if (stack.size() < 2) {
        reset();
		throw StackError("Error: empty stack");
	}
	IOperand const *a = stack.back();
	pop();
	IOperand const *b = stack.back();
	pop();
	stack.push_back(*b % *a);
    delete a;
    delete b;
}

void
Executor::print( ) {
	IOperand const *a = stack.back();
	if (a->getType() == 0) {
		char c = stoi(a->toString());
		if (c >= 32 && c <= 126)
		    std::cout << c << std::endl;
		else {
            reset();
            throw StackError("Print error: " + a->toString() + " is not printable");
		}
	}
	else {
        reset();
		throw StackError("Print error: " + a->toString() + " is not int8");
	}
}

void
Executor::exit( ) {
	exit_ = true;
}

void
Executor::push( std::string type, std::string value ) {
	eOperandType e_type = Int8;
	if (type == "int16")
		e_type = Int16;
	else if (type == "int32")
		e_type = Int32;
	else if (type == "float")
		e_type = Float;
	else if (type == "double")
		e_type = Double;
	Factory creator;
	stack.push_back(creator.createOperand(e_type, value));
}

void
Executor::assert( std::string type, std::string value ) {
	eOperandType e_type = Int8;
	if (type == "int16")
		e_type = Int16;
	else if (type == "int32")
		e_type = Int32;
	else if (type == "float")
		e_type = Float;
	else if (type == "double")
		e_type = Double;
	if (value != stack.back()->toString() || e_type != stack.back()->getType()) {
	    reset();
		throw StackError("Assert error!");
	}
}

void
Executor::reset(){
    while(!stack.empty()) {
        IOperand const *a = stack.back();
        stack.pop_back();
        delete a;
    }
    exit_ = false;
}

Executor &
Executor::operator=( Executor const & rhs) {
	(void)rhs;
	return *this;
}