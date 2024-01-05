#include "RPN.hpp"

RPN::RPN() {
	std::cout << "Default Constructor Called" << std::endl;
}

RPN::RPN(const RPN& other) {
	std::cout << "Copy Constructor Called" << std::endl;
	(void)other;
}

RPN::~RPN() {
	std::cout << "Destructor Called" << std::endl;
}

RPN&	RPN::operator=(const RPN& other) {
	std::cout << "Copy Assignment Operator Called" << std::endl;
	if (this != &other) {
	}
	return (*this);
}

