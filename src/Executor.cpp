//
// Created by Anastasiia ORJI on 12/22/18.
//

#include "../inc/Executor.hpp"

Executor::Executor(): exit_(false) {
	cmd.push_back(&Executor::pop);
	cmd.push_back(&Executor::dump);
	cmd.push_back(&Executor::add);
	cmd.push_back(&Executor::sub);
	cmd.push_back(&Executor::mul);
	cmd.push_back(&Executor::div);
	cmd.push_back(&Executor::mod);
	cmd.push_back(&Executor::print);
	cmd.push_back(&Executor::exit);
	// cmd.push_back(&Executor::push);
	// cmd.push_back(&Executor::assert);
}

Executor::~Executor() {}

void
Executor::run(std::vector<std::map<std::string, std::string>> data) {
	for(auto & v: data){
		if (exit_)
			break;
		if (v["cmd"] == "pop")
			(this->*cmd.at(0))();
		else if (v["cmd"] == "dump")
			(this->*cmd.at(1))();
		else if (v["cmd"] == "add")
			(this->*cmd.at(2))();
		else if (v["cmd"] == "sub")
			(this->*cmd.at(3))();
		else if (v["cmd"] == "mul")
			(this->*cmd.at(4))();
		else if (v["cmd"] == "div")
			(this->*cmd.at(5))();
		else if (v["cmd"] == "mod")
			(this->*cmd.at(6))();
		else if (v["cmd"] == "print")
			(this->*cmd.at(7))();
		else if (v["cmd"] == "exit")
			(this->*cmd.at(8))();
		else if (v["cmd"] == "push")
			push( v["type"], v["value"] );
		// 	(this->*cmd.at(9))(v["type"], v["value"]);
		else if (v["cmd"] == "assert")
			assert( v["value"] );
		// 	(this->*cmd.at(10))(v["value"]);
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
   for(auto & v: stack)
       std::cout << v->toString() << std::endl;
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