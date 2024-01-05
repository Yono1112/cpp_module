#include "RPN.hpp"

RPN::RPN() 
	: _stack() {
	// std::cout << "Default Constructor Called" << std::endl;
}

RPN::RPN(const RPN& other) 
	: _stack(other._stack) {
	// std::cout << "Copy Constructor Called" << std::endl;
}

RPN::~RPN() {
	// std::cout << "Destructor Called" << std::endl;
}

RPN&	RPN::operator=(const RPN& other) {
	// std::cout << "Copy Assignment Operator Called" << std::endl;
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

void	RPN::popStackAndCalc(const char c) {
	if (_stack.empty()) {
		throw std::out_of_range("stack is empty");
	}
	int first, second;
	second = _stack.top();
	_stack.pop();
	if (_stack.empty()) {
		throw std::out_of_range("stack is empty");
	}
	first = _stack.top();
	_stack.pop();
	if (c == '+') {
		_stack.push(first + second);
	} else if (c == '-') {
		_stack.push(first - second);
	} else if (c == '*') {
		_stack.push(first * second);
	} else if (c == '/') {
		_stack.push(first / second);
	}
	// std::cout << "stack top: " << _stack.top() << std::endl;
	// std::cout << "arithmetic: " << c << "first: " << first << ", second: " << second << std::endl;
}

void	RPN::pushStack(const char c) {
	// std::cout << "run pushStack, c: " << c << std::endl;
	int num = c - '0';

	// std::cout << "num: " << num << std::endl;
	_stack.push(num);
	// std::cout << "_stack top: " << _stack.top() << std::endl;
}

void	RPN::calcReversePolish(const char *c_str) {
	// std::cout << "run calcReversePolish" << std::endl;
	std::string str(c_str);
	// std::cout << str << std::endl;

	size_t i = 0;
	while (i < str.size()) {
		// std::cout << "===================" << std::endl;
		skipSpace(str, i);
		if (isArithmetic(str[i])) {
			// std::cout << str[i] << std::endl;
			popStackAndCalc(str[i]);
			i++;
		} else {
			// std::cout << str[i] << std::endl;
			pushStack(str[i]);
			i++;
		}
	}
	if (_stack.size() > 1) {
		throw std::out_of_range("there are too many nums");
	} else {
		std::cout << _stack.top() << std::endl;
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
