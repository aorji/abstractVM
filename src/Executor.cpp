//
// Created by Anastasiia ORJI on 12/22/18.
//

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

void
Executor::run(std::vector<std::map<std::string, std::string>> data) {
	for(auto & v: data){
		if (exit_)
			break;
		if (v["cmd"] != "push" && v["cmd"] != "assert" && v["cmd"] != "")
			(this->*instruction[v["cmd"]])();
		if (v["cmd"] == "push")
		 	push(v["type"], v["value"]);
		else if (v["cmd"] == "assert")
			assert( v["value"] );
	}
	if (!exit_)
		throw StackError("no exit instruction");
}

void
Executor::pop( ) {
   if (stack.empty())
       throw StackError("not enough elements");
   stack.pop_back();
}

void
Executor::dump( ) {
   for(auto it = stack.rbegin(); it != stack.rend(); ++it)
    	std::cout << (*it)->toString() << std::endl;
}

void
Executor::add( ) {
	if (stack.size() < 2)
		throw StackError("not enough elements");
	IOperand const *a = stack.back();
	pop();
	IOperand const *b = stack.back();
	pop();
	stack.push_back(*a + *b);
}

void
Executor::sub( ) {
	if (stack.size() < 2)
		throw StackError("not enough elements");
	IOperand const *a = stack.back();
	pop();
	IOperand const *b = stack.back();
	pop();
	stack.push_back(*a - *b);
}

void
Executor::mul( ) {
	if (stack.size() < 2)
		throw StackError("not enough elements");
	IOperand const *a = stack.back();
	pop();
	IOperand const *b = stack.back();
	pop();
	stack.push_back(*a * *b);
}

void
Executor::div( ) {
	if (stack.size() < 2)
		throw StackError("not enough elements");
	IOperand const *a = stack.back();
	pop();
	IOperand const *b = stack.back();
	pop();
	stack.push_back(*a / *b);
}

void
Executor::mod( ) {
	if (stack.size() < 2)
		throw StackError("not enough elements");
	IOperand const *a = stack.back();
	pop();
	IOperand const *b = stack.back();
	pop();
	stack.push_back(*a % *b);
}

void
Executor::print( ) {
	IOperand const *a = stack.back();
	if (a->getType() == 0) {
		char c = stoi(a->toString());
		std::cout << c << std::endl;
	}
	else
		throw StackError(a->toString() + " is not int8");
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
Executor::assert( std::string value ) {
	if (value != stack.back()->toString())
		throw StackError(value + " != " + stack.back()->toString());
}