#ifndef EXEPTION_HPP
#define EXEPTION_HPP

class EmptyStackException: public std::exception {
	public:
		EmptyStackException( void );
		EmptyStackException( EmptyStackException const & src );
		~EmptyStackException( void ) throw();
		EmptyStackException & operator=( EmptyStackException const & rhs);
		const char* what() const throw();
};

#endif