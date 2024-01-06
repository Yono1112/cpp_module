#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {
	std::cout << "Default Constructor Called" << std::endl;
}

PmergeMe::PmergeMe(const PmergeMe& other) {
	std::cout << "Copy Constructor Called" << std::endl;
	(void)other;
}

PmergeMe::~PmergeMe() {
	std::cout << "Destructor Called" << std::endl;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
	std::cout << "Copy Assignment Operator Called" << std::endl;
	if (this != &other) {

	}
	return (*this);
}

