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
		template <typename Iterator>
		void	fillNumbers(Iterator begin, Iterator end);
	private:
		unsigned int _max_elements;
		std::multiset<int> _mset;
};

template <typename Iterator>
void	Span::fillNumbers(Iterator begin, Iterator end) {
	while (begin != end) {
		addNumber(*begin);
		begin++;
	}
}

#endif
