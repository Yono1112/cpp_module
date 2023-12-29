#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>

class Span {
	public:
		Span();	
		Span(unsigned int n);	
		Span(const Span& other);	
		Span& operator=(const Span& other);
		~Span();
		void	addNumber(int num);
		// unsigned int	shortestSpan();
		// unsigned int	longestSpan();
	private:
		unsigned int _max_elements;
		std::vector<int> _vec;
};

#endif
