#include "Span.hpp"

int	main () {
	try {
		int n = 10;
		int i = 0;
		Span sp(n);
		for (; i < n; i++) {
			sp.addNumber(i);
		}
		sp.addNumber(i + 1);
	} catch (const std::exception& e) {
		std::cout << "catch exception: " << e.what() << std::endl;
	}
	return (0);
}
