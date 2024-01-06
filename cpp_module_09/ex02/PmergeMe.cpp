#include "PmergeMe.hpp"

PmergeMe::PmergeMe() 
	: _vec()
	, _lst() {
	std::cout << "Default Constructor Called" << std::endl;
}

PmergeMe::PmergeMe(const PmergeMe& other)
	: _vec(other._vec)
	, _lst(other._lst) {
	std::cout << "Copy Constructor Called" << std::endl;
}

PmergeMe::~PmergeMe() {
	std::cout << "Destructor Called" << std::endl;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
	std::cout << "Copy Assignment Operator Called" << std::endl;
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

void	PmergeMe::setVectorAndList(const char *c_str) {
	std::string str(c_str);
	std::istringstream iss(str);
	unsigned int num;

	while (iss >> num) {
		_vec.push_back(num);
		_lst.push_back(num);
	}
	for (size_t i = 0; i < _vec.size(); i++) {
		std::cout << "vec[" << i << "]: " << _vec.at(i) << std::endl;
	}
	for (std::list<unsigned int>::iterator it = _lst.begin(); it != _lst.end(); it++) {
		std::cout << "lst: " << *it << std::endl;
	}
}
