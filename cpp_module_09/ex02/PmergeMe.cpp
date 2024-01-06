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
	std::cout << "std::vec " << str;
	for (size_t i = 0; i < _vec.size(); i++) {
		std::cout << _vec.at(i) << " ";
	}
	std::cout << std::endl;
	std::cout << "std::lst " << str;
	for (std::list<unsigned int>::iterator it = _lst.begin(); it != _lst.end(); it++) {
		std::cout << *it << " ";
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

void	PmergeMe::runInsertionSortVector() {
	for (size_t i = 1; i < _vec.size(); i++) {
		insert(i - 1, _vec[i]);
	}
}

void	PmergeMe::merge(int left, int middle, int right) {
	// std::cout << "merge" << std::endl;
	int left_index = left;
	int right_index = middle + 1;
	std::vector<unsigned int> tmp_vec;

	while (left_index <= middle && right_index <= right) {
		if (_vec[left_index] < _vec[right_index]) {
			tmp_vec.push_back(_vec[left_index++]);
		} else {
			tmp_vec.push_back(_vec[right_index++]);
		}
	}

	while (left_index <= middle) {
		tmp_vec.push_back(_vec[left_index++]);
	}
	while (right_index <= right) {
		tmp_vec.push_back(_vec[right_index++]);
	}
	for (int i = left; i <= right; i++) {
		_vec[i] = tmp_vec[i - left];
	}
}

void	PmergeMe::runMergeSortVector(int left, int right) {
	if (left == right) {
		return ;
	}
	int middle = (right + left) / 2;
	// std::cout << "left: " << left << ", right: " << right << ", middle: " << middle << std::endl;
	runMergeSortVector(left, middle);
	runMergeSortVector(middle + 1, right);
	merge(left, middle, right);
}

void	PmergeMe::sortVector() {
	// if (_vec.size() > 100) {
		std::cout << "runMergeSortVector" << std::endl;
		runMergeSortVector(0, _vec.size() - 1);
	// } else {
	// 	std::cout << "runInsertionSortVector" << std::endl;
	// 	runInsertionSortVector();
	// }
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
