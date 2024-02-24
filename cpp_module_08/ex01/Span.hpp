#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <set>

class Span {
	public:
		Span();	
		Span(unsigned int n);
		Span(const Span& other);	
		Span& operator=(const Span& other);
		~Span();
		void	addNumber(int num);
		unsigned int	shortestSpan();
		unsigned int	longestSpan();
		void	fillNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);
	private:
		unsigned int _max_elements;
		std::multiset<int> _mset;
};

#endif
