#include "Span.hpp"
#include <cstdlib>

void	testSubject() {
	std::cout << "====================================" << std::endl;
	std::cout << "run testSubject" << std::endl;
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

void	testInvalidSpan() {
	std::cout << "====================================" << std::endl;
	std::cout << "run testInvalidSpan" << std::endl;
	const unsigned int N = 10;
	Span sp1(N);
	Span sp2(sp1);

	try {
		std::cout << "test adding more than the maximum number of elements" << std::endl;
		for (unsigned int i = 0; i < N + 1; i ++) {
			std::cout << "addNumber: " << i << std::endl;
			sp1.addNumber(i);
		}
	} catch (const std::exception& e) {
		std::cout << "catch exception: " << e.what() << std::endl;
	}
	try {
		std::cout << "test shortestSpan() when there are no numbers stored" << std::endl;
		std::cout << "shortestSpan: " << sp2.shortestSpan() << std::endl;
	} catch (const std::exception& e) {
		std::cout << "catch exception: " << e.what() << std::endl;
	}
	try {
		std::cout << "test longestSpan() when there are only one numbers stored" << std::endl;
		sp2.addNumber(N);
		std::cout << "longestSpan: " << sp2.longestSpan() << std::endl;
	} catch (const std::exception& e) {
		std::cout << "catch exception: " << e.what() << std::endl;
	}
}

void	testValidSpan() {
	std::cout << "====================================" << std::endl;
	std::cout << "run testValidSpan" << std::endl;
	const unsigned int N = 20000;
	Span sp(N);
	std::vector<int> vec;

	std::cout << "std::vector size: " << vec.size() << std::endl;
	for (unsigned int i = 1; i < N + 1; ++i) {
		vec.push_back(i);
	}
	std::cout << "std::vector size: " << vec.size() << std::endl;
	{
		try {
			sp.fillNumbers(vec.begin(), vec.end());

			std::cout << "shortestSpan: " << sp.shortestSpan() << std::endl;
			std::cout << "longestSpan: " << sp.longestSpan() << std::endl;
		} catch (const std::exception& e) {
			std::cout << "catch exception: " << e.what() << std::endl;
		}
	}
	{
		srand(time(NULL));
		const unsigned int N = 100;
		Span sp(N);
		std::vector<int> vec;

		std::cout << "std::vector size: " << vec.size() << std::endl;
		for (unsigned int i = 0; i < N ; ++i) {
			vec.push_back(rand() % 10000);
		}
		std::cout << "std::vector size: " << vec.size() << std::endl;
		try {
			sp.fillNumbers(vec.begin(), vec.end());
	     	
			std::cout << "shortestSpan: " << sp.shortestSpan() << std::endl;
			std::cout << "longestSpan: " << sp.longestSpan() << std::endl;
		} catch (const std::exception& e) {
			std::cout << "catch exception: " << e.what() << std::endl;
		}
	}
	{
		Span span(3);
		try {
			span.addNumber(-2147483648);
			span.addNumber(2147483647);

			std::cout << "shortestSpan: " << span.shortestSpan() << std::endl;
			std::cout << "longestSpan: " << span.longestSpan() << std::endl;
			std::cout << "addNumber(0)" << std::endl;
			span.addNumber(0);
			std::cout << "shortestSpan: " << span.shortestSpan() << std::endl;
			std::cout << "longestSpan: " << span.longestSpan() << std::endl;
		} catch (const std::exception& e) {
			std::cout << "catch exception: " << e.what() << std::endl;
		}
	}
}

int	main() {
	testSubject();
	testInvalidSpan();
	testValidSpan();
	return (0);
}
