#include "PmergeMe.hpp"

PmergeMe::PmergeMe() 
	: _vec()
	, _lst() {
	// std::cout << "Default Constructor Called" << std::endl;
}

PmergeMe::PmergeMe(const PmergeMe& other)
	: _vec(other._vec)
	, _lst(other._lst) {
	// std::cout << "Copy Constructor Called" << std::endl;
}

PmergeMe::~PmergeMe() {
	// std::cout << "Destructor Called" << std::endl;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
	// std::cout << "Copy Assignment Operator Called" << std::endl;
	if (this != &other) {
		this->_vec = other._vec;
		this->_lst = other._lst;
	}
	return (*this);
}

bool	PmergeMe::checkValidArgs(const char *str) {
	for (size_t i = 0; str[i]; i++) {
		if (!std::isdigit(str[i]) && str[i] != ' ') {
			return (false);
		}
	}
	return (true);
}

void	PmergeMe::printFirstSecondLine(const std::string& str) {
	std::cout << str;
	for (size_t i = 0; i < _vec.size(); i++) {
		std::cout << _vec.at(i) << " ";
	}
	std::cout << std::endl;
}

void	PmergeMe::setVectorAndList(const char *c_str) {
	std::string str(c_str);
	std::istringstream iss(str);
	unsigned int num;

	while (iss >> num) {
		_vec.push_back(num);
		_lst.push_back(num);
	}
	printFirstSecondLine("Before: ");
	// for (size_t i = 0; i < _vec.size(); i++) {
	// 	std::cout << "vec[" << i << "]: " << _vec.at(i) << std::endl;
	// }
	// for (std::list<unsigned int>::iterator it = _lst.begin(); it != _lst.end(); it++) {
	// 	std::cout << "lst: " << *it << std::endl;
	// }
}

void	PmergeMe::insert(int sorted_index, const unsigned int element) {
	while (sorted_index >= 0) {
		if (element > _vec[sorted_index]) {
			break ;
		}
		_vec[sorted_index + 1] = _vec[sorted_index];
		sorted_index--;
	}
	_vec[sorted_index + 1] = element;
}

void	PmergeMe::sortVector() {
	for (size_t i = 1; i < _vec.size(); i++) {
		insert(i - 1, _vec[i]);
	}
	// for (size_t i = 0; i < _vec.size(); i++) {
	// 	std::cout << "vec[" << i << "]: " << _vec.at(i) << std::endl;
	// }
}

void	PmergeMe::insert(std::list<unsigned int>::iterator sorted_index, const unsigned int element) {
	while (sorted_index != _lst.begin()) {
		if (element > *std::prev(sorted_index)) {
			break ;
		}
		*sorted_index = *std::prev(sorted_index);
		sorted_index--;
	}
	*sorted_index = element;
}

void	PmergeMe::sortList() {
	for (std::list<unsigned int>::iterator it = _lst.begin(); it != _lst.end(); it++) {
		insert(it, *it);
	}
	// for (std::list<unsigned int>::iterator it = _lst.begin(); it != _lst.end(); it++) {
	// 	std::cout << "lst: " << *it << std::endl;
	// }
}

void	PmergeMe::printSortTime(const std::string& container, const double time, const size_t size) {
	std::cout << "Time to process a range of " << size << " elements with std::" << container << " : " << time << " us" << std::endl;
}

void	PmergeMe::sortMergeInsertion() {
	// std::cout << "==============" << std::endl;
	// std::cout << "run sortMergeInsertion" << std::endl;
	std::clock_t start_vec = std::clock();
	sortVector();
	std::clock_t end_vec = std::clock();
	std::clock_t start_lst = std::clock();
	sortList();
	std::clock_t end_lst = std::clock();
	double time_vec = 1000000.0 * (static_cast<double>(end_vec) - static_cast<double>(start_vec)) / CLOCKS_PER_SEC;
	double time_lst = 1000000.0 * (static_cast<double>(end_lst) - static_cast<double>(start_lst)) / CLOCKS_PER_SEC;
	printFirstSecondLine("After: ");
	printSortTime("vector", time_vec, _vec.size());
	printSortTime("list", time_lst, _lst.size());
}
