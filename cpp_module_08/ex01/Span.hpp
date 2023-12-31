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
		void	fillNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);
	private:
		unsigned int _max_elements;
		std::vector<int> _vec;
};

#endif
