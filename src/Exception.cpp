//
// Created by Anastasiia ORJI on 13/12/2018.
//
//EmptyStackException::EmptyStackException ( void ) {}
//
//EmptyStackException::EmptyStackException ( EmptyStackException const & src ) {
//	*this = src;
//}
//
//EmptyStackException::~EmptyStackException ( void ) throw() {}
//
//EmptyStackException &
//EmptyStackException::operator=( EmptyStackException::EmptyStackException const & rhs) {
//	(void)rhs;
//	return *this;
//}
//
//const char *
//EmptyStackException::what() const throw()
//{
//    return ("Stack is empty!");
//}