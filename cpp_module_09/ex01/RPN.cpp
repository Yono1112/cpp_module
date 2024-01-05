#include "RPN.hpp"

RPN::RPN() 
	: _stack() {
	std::cout << "Default Constructor Called" << std::endl;
}

RPN::RPN(const RPN& other) 
	: _stack(other._stack) {
	std::cout << "Copy Constructor Called" << std::endl;
}

RPN::~RPN() {
	std::cout << "Destructor Called" << std::endl;
}

RPN&	RPN::operator=(const RPN& other) {
	std::cout << "Copy Assignment Operator Called" << std::endl;
	if (this != &other) {
		this->_stack = other._stack;
	}
	return (*this);
}

bool	RPN::isArithmetic(const char c) {
	return (c == '+' || c == '-' || c == '/' || c == '*');
}

bool	RPN::checkValidChar(const char c) {
	if (!std::isdigit(c) && c != ' ' && !isArithmetic(c)) {
		return (false);
	}
	return (true);
}

bool	RPN::checkArguments(const char *argv) {
	for (size_t i = 0; argv[i]; i++) {
		if (!checkValidChar(argv[i])) {
			return (false);
		}
	}
	return (true);
}
