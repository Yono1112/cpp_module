#include "Span.hpp"

Span::Span() 
	: _max_elements(0)
	, _vec(0) {
	std::cout << "Span Default Constructor Called" << std::endl;
}

Span::Span(unsigned int n)
	: _max_elements(n)
	, _vec(0) {
	std::cout << "Span Argument Constructor Called" << std::endl;
}

Span::Span(const Span& other)
	: _max_elements(other._max_elements)
	, _vec(other._vec){
	std::cout << "Span Copy Constructor Called" << std::endl;
}

Span& Span::operator=(const Span& other) {
	std::cout << "Span Copy Assignment Operator Called" << std::endl;
	if (this != &other) {
		this->_max_elements = other._max_elements;
		this->_vec = other._vec;
	}
	return (*this);
}

Span::~Span() {
	std::cout << "Span Destructor Called" << std::endl;
}

void	Span::addNumber(int num) {
	// std::cout << "run addNumber" << std::endl;
	if (_vec.size() >= _max_elements) {
		throw std::length_error("there are already max elements stored");
	} else {
		_vec.push_back(num);
		std::cout << _vec.size() << ": " << _vec.at(num) << std::endl;
	}
}
