#include "Span.hpp"
#include <cstddef>

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
	}
}

int	Span::shortestSpan() {
	if (_vec.empty() ||_vec.size() < 2) {
		throw std::range_error("the number of elements is too small");
	}
	std::vector<int> sort_vec = _vec;
	int shortest_span = INT_MAX;
	std::sort(sort_vec.begin(), sort_vec.end());
	// for (size_t i = 0; i < sort_vec.size(); i++) {
	// 	std::cout << i << ": " << sort_vec.at(i) << std::endl;
	// }
	for (size_t i = 0; i < sort_vec.size() - 1; i++) {
		if (sort_vec.at(i + 1) - sort_vec.at(i) < shortest_span)
			shortest_span = sort_vec.at(i + 1) - sort_vec.at(i);
	}
	return (shortest_span);
}

int	Span::longestSpan() {
	if (_vec.empty() ||_vec.size() < 2) {
		throw std::range_error("the number of elements is too small");
	}
	std::vector<int>::iterator min = std::min_element(_vec.begin(), _vec.end());
	std::vector<int>::iterator max = std::max_element(_vec.begin(), _vec.end());
	return (*(max) - *(min));
}
