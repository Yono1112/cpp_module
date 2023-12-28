#include "easyfind.hpp"
#include <vector>
#include <list>
#include <cstddef>
#include <iostream>

void	testValidVector() {
	std::cout << "=========================================" << std::endl;
	std::cout << "run testValidList" << std::endl;
	try {
		std::vector<int> vec;
		for (size_t i = 0; i < 10; i++) {
			vec.push_back(i);
			std::cout << "vec[" << i << "]: " << vec.at(i) << std::endl;
		}
		for (size_t i = 0; i < 10; i++) {
			std::cout << i << ": "<< std::boolalpha << easyfind(vec, i) << std::endl;
		}
	} catch (const std::exception& e) {
		std::cerr << "catch std::exception: " << e.what() << std::endl;
	}
}

void	testInvalidVector() {
	std::cout << "=========================================" << std::endl;
	std::cout << "run testInvalidVector" << std::endl;
	std::vector<int> vec;
	for (size_t i = 0; i < 10; i++) {
		vec.push_back(i);
	}
	try {
		std::cout << "-1: "<< std::boolalpha << easyfind(vec, -1) << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "catch std::exception: " << e.what() << std::endl;
	}
	try {
		std::cout << "11: "<< std::boolalpha << easyfind(vec, 11) << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "catch std::exception: " << e.what() << std::endl;
	}
}

void	testValidList() {
	std::cout << "=========================================" << std::endl;
	std::cout << "run testValidList" << std::endl;
	try {
		std::list<int> lst;
		for (size_t i = 0; i < 10; i++) {
			lst.push_front(i);
		}
		for (size_t i = 0; i < 10; i++) {
			std::cout << i << ": "<< std::boolalpha << easyfind(lst, i) << std::endl;
		}
	} catch (const std::exception& e) {
		std::cerr << "catch std::exception: " << e.what() << std::endl;
	}
}

void	testInvalidList() {
	std::cout << "=========================================" << std::endl;
	std::cout << "run testInvalidList" << std::endl;
	std::list<int> lst;
	for (size_t i = 0; i < 10; i++) {
		lst.push_front(i);
	}
	try {
		std::cout << "-1: "<< std::boolalpha << easyfind(lst, -1) << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "catch std::exception: " << e.what() << std::endl;
	}
	try {
		std::cout << "-1: "<< std::boolalpha << easyfind(lst, -1) << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "catch std::exception: " << e.what() << std::endl;
	}
}

int	main() {
	testValidVector();
	testInvalidVector();
	testValidList();
	testInvalidList();
}
