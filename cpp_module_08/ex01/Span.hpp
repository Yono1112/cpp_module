#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>

class Span {
	public:
		Span();	
		Span(unsigned int n);	
		Span(const Span& other);	
		Span& operator=(const Span& other);
		~Span();
		void	addNumber(int num);
		std::vector<int>::iterator	shortestSpan();
		std::vector<int>::iterator	longestSpan();
	private:
		unsigned int _max_elements;
		std::vector<int> _vec;
};

#endif
