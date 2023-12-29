#include "Span.hpp"

void	testSubject() {
	try {
		Span sp = Span(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << "shortestSpan: " << sp.shortestSpan() << std::endl;
		std::cout << "longestSpan: " << sp.longestSpan() << std::endl;
	} catch (const std::exception& e) {
		std::cout << "catch exception: " << e.what() << std::endl;
	}
}

int	main() {
	testSubject();
	try {
		int n = 10;
		int i = 0;
		Span sp(n);
		for (; i < n; i++) {
			sp.addNumber(i);
		}
		std::cout << "shortestSpan: " << sp.shortestSpan() << std::endl;
		std::cout << "longestSpan: " << sp.longestSpan() << std::endl;
	} catch (const std::exception& e) {
		std::cout << "catch exception: " << e.what() << std::endl;
	}
	return (0);
}
