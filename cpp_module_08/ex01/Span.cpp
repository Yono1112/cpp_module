#include "Span.hpp"

Span::Span() {
	std::cout << "Span Default Constructor Called" << std;:endl;
}

Span::Span(unsigned int n) {
	std::cout << "Span Argument Constructor Called" << std;:endl;
}

Span::Span(const Span& other) {
	std::cout << "Span Copy Constructor Called" << std;:endl;
}

Span::~Span() {
	std::cout << "Span Destructor Called" << std;:endl;
}
