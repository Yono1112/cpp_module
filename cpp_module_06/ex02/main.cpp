#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>

Base*	generate(void) {
	std::srand(time(NULL));
	int index = rand() % 3;
	if (index == 0) {
		std::cout << "A class" << std::endl;
		return (new A());
	} else if (index == 1) {
		std::cout << "B class" << std::endl;
		return (new B());
	} else {
		std::cout << "C class" << std::endl;
		return (new C());
	}
}

void	identify(Base* p) {
	std::cout << "actual type: ";
	if (dynamic_cast<A *>(p) != NULL) {
		std::cout << "A";
	} else if (dynamic_cast<B *>(p) != NULL) {
		std::cout << "B";
	} else if (dynamic_cast<C *>(p) != NULL) {
		std::cout << "C";
	}
	std::cout << std::endl;
}

void	identify(Base& p) {
	std::cout << "actual type: ";
	try {
		A& ref = dynamic_cast<A &>(p);
		std::cout << "A";
		(void)ref;
	} catch (const std::bad_cast&) {
	}
	try {
		B& ref = dynamic_cast<B &>(p);
		std::cout << "B";
		(void)ref;
	} catch (const std::bad_cast&) {
	}
	try {
		C& ref = dynamic_cast<C &>(p);
		std::cout << "C";
		(void)ref;
	} catch (const std::bad_cast&) {
	}
	std::cout << std::endl;
}

int main() {
	Base* ptr = generate();
	identify(ptr);
	Base& ref = *ptr;
	identify(ref);
	(void)ref;
	delete ptr;
	return (0);
}
