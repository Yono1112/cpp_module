#include "Span.hpp"
#include <cstddef>

Span::Span() 
	: _max_elements(0)
	, _mset() {
	std::cout << "Span Default Constructor Called" << std::endl;
}

Span::Span(unsigned int n)
	: _max_elements(n)
	, _mset() {
	std::cout << "Span Argument Constructor Called" << std::endl;
}

Span::Span(const Span& other)
	: _max_elements(other._max_elements)
	, _mset(other._mset){
	std::cout << "Span Copy Constructor Called" << std::endl;
}

Span& Span::operator=(const Span& other) {
	std::cout << "Span Copy Assignment Operator Called" << std::endl;
	if (this != &other) {
		this->_max_elements = other._max_elements;
		this->_mset = other._mset;
	}
	return (*this);
}

Span::~Span() {
	std::cout << "Span Destructor Called" << std::endl;
}

void	Span::addNumber(int num) {
	// std::cout << "run addNumber" << std::endl;
	if (_mset.size() >= _max_elements) {
		throw std::length_error("there are already max elements stored");
	} else {
		_mset.insert(num);
	}
}

unsigned int	Span::shortestSpan() {
	if (_mset.empty() ||_mset.size() < 2) {
		throw std::range_error("the number of elements is too small");
	}
	unsigned int shortest_span = std::numeric_limits<unsigned int>::max();
	std::multiset<int>::iterator it = _mset.begin();
	std::multiset<int>::iterator prev_it = it;
	it++;
	for (; it != _mset.end(); ++it) {
		long prev_num;
		if (*it > 0 && *prev_it < 0) {
			prev_num = -*prev_it;
		} else {
			prev_num = *prev_it;
		}
		unsigned int span = std::abs(*it - prev_num);
		if (span < shortest_span) {
			shortest_span = span;
		}
		prev_it++;
	}
	return (shortest_span);
}

unsigned int	Span::longestSpan() {
	if (_mset.empty() ||_mset.size() < 2) {
		throw std::range_error("the number of elements is too small");
	}
	std::multiset<int>::iterator min = std::min_element(_mset.begin(), _mset.end());
	std::multiset<int>::iterator max = std::max_element(_mset.begin(), _mset.end());
	unsigned int min_num;
	if (*min < 0) {
		min_num = -*min;
	} else {
		min_num = *min;
	}
	return (*max - min_num);
}

void	Span::fillNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
	while (begin != end) {
		addNumber(*begin);
		begin++;
	}
}
