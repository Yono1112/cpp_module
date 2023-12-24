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

// void	identify(Base* p) {
// 
// }
// 
// void	identify(Base& p) {
// 
// }

int main() {
	Base* ptr = generate();
	std::cout << ptr << std::endl;
	delete ptr;
	return (0);
}
