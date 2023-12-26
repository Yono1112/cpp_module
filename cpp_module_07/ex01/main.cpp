#include "iter.hpp"
#include <iostream>
#include <string>
#include <sstream>

void	printArg(int arg) {
	std::cout << "arg: " << arg << std::endl;
}

void	printArg(double arg) {
	std::cout << "arg: " << arg << std::endl;
}

void	printArg(std::string arg) {
	std::cout << "arg: " << arg << std::endl;
}

void	testInt() {
	int	array[10];

	for (int i = 0; i < 10; i++) {
		array[i] = i;
		std::cout << "array[" << i << "]: "<< array[i] << std::endl;
	}
	iter(array, sizeof(array) / sizeof(array[0]), printArg);
}

void	testDouble() {
	double	array[10];

	for (int i = 0; i < 10; i++) {
		array[i] = static_cast<double>(i) + 0.5;
		std::cout << "array[" << i << "]: "<< array[i] << std::endl;
	}
	iter(array, sizeof(array) / sizeof(array[0]), printArg);
}

void	testString() {
	std::string	array[10];

	for (int i = 0; i < 10; i++) {
		array[i].append("hoge");
		std::cout << "array[" << i << "]: "<< array[i] << std::endl;
	}
	iter(array, sizeof(array) / sizeof(array[0]), printArg);
}

int	main () {
	testInt();
	testDouble();
	testString();
	return (0);
}
