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
		int	shortestSpan();
		int	longestSpan();
	private:
		unsigned int _max_elements;
		std::vector<int> _vec;
};

#endif
