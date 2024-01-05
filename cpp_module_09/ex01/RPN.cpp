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

void	RPN::skipSpace(const std::string& str, size_t& i) {
	while (str[i] == ' ') {
		i++;
	}
}

void	RPN::calcReversePolish(const char *c_str) {
	std::cout << "run calcReversePolish" << std::endl;
	std::string str(c_str);
	std::cout << str << std::endl;

	for (size_t i = 0; i < str.size(); i++) {
		skipSpace(str, i);
		if (isArithmetic(str[i])) {
			std::cout << str[i] << std::endl;
			// popStackAndCalc(str[i]);
		} else {
			std::cout << str[i] << std::endl;
			// pushStack(str, i);
		}
	}
}

bool	RPN::isArithmetic(const char c) {
	return (c == '+' || c == '-' || c == '/' || c == '*');
}

bool	RPN::checkValidChar(const char c) {
	return (std::isdigit(c) || c == ' ' || isArithmetic(c));
}

bool	RPN::checkArguments(const char *argv) {
	for (size_t i = 0; argv[i]; i++) {
		if (!checkValidChar(argv[i])) {
			return (false);
		} else if (std::isdigit(argv[i]) && std::isdigit(argv[i + 1])) {
			return (false);
		}
	}
	return (true);
}
