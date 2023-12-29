#include "Span.hpp"

int	main () {
	try {
		int n = 10;
		int i = 0;
		Span sp(n);
		for (; i < n; i++) {
			sp.addNumber(i);
		}
		std::cout << *(sp.shortestSpan()) << std::endl;
		std::cout << *(sp.longestSpan()) << std::endl;
	} catch (const std::exception& e) {
		std::cout << "catch exception: " << e.what() << std::endl;
	}
	return (0);
}
