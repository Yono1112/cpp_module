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
	for (std::list<int>::iterator it = _lst.begin(); it != _lst.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

void	PmergeMe::setVectorAndList(const char *c_str) {
	std::string str(c_str);
	std::istringstream iss(str);
	long num;

	while (iss >> num) {
		if (std::numeric_limits<int>::max() < num || std::numeric_limits<int>::min() > num) {
			throw std::out_of_range("int out of range");
		}
		_vec.push_back(num);
		_lst.push_back(num);
	}
	// std::cout << "_vec: ";
	// for (size_t i = 0; i < _vec.size(); i++) {
	// 	std::cout << _vec.at(i) << ", ";
	// }
	// std::cout << std::endl;
	// for (std::list<int>::iterator it = _lst.begin(); it != _lst.end(); it++) {
	// 	std::cout << "lst: " << *it << std::endl;
	// }
}

unsigned int	PmergeMe::jacobsthal(const unsigned int n) {
	if (n == 0) {
		return (0);
	} else if (n == 1) {
		return (1);
	}
	std::vector<unsigned int> jacobsthal_nums(n + 1);
	jacobsthal_nums[0] = 0;
	jacobsthal_nums[1] = 1;
	for (unsigned int i = 2; i <= n; ++i) {
		jacobsthal_nums[i] = jacobsthal_nums[i - 1] + 2 * jacobsthal_nums[i - 2];
	}
	return (jacobsthal_nums[n]);
}

std::vector<unsigned int>	PmergeMe::createJacobstalVector(const size_t max_num) {
	std::vector<unsigned int> jacobsthal_vec;
	for (size_t i = 0;; ++i) {
		unsigned int jacob_num = jacobsthal(i);
		if (jacob_num >= max_num) {
			jacobsthal_vec.push_back(max_num);
			break ;
		}
		jacobsthal_vec.push_back(jacob_num);
	}
	return (jacobsthal_vec);
}

std::vector<unsigned int>	PmergeMe::createJacobstalIndex(const std::vector<int>& smaller_vec) {
	std::vector<unsigned int> jacobsthal_vec = createJacobstalVector(smaller_vec.size());
	std::vector<unsigned int> index_vec;
	for (size_t i = 1; i < jacobsthal_vec.size(); ++i) {
		unsigned int prev_num = jacobsthal_vec[i - 1];
		for (unsigned int j = jacobsthal_vec[i]; j > prev_num; --j) {
			index_vec.push_back(j);
		}
	}
	// for (unsigned int i = 0; i < index_vec.size(); ++i) {
	// 	std::cout << index_vec[i] << ", ";
	// }
	// std::cout << std::endl;
	return (index_vec);
}

void	PmergeMe::runBinaryInsertionSort(std::vector<int>& main_chain, const int sub_chain_element) {
	std::vector<int>::iterator it = std::lower_bound(main_chain.begin(), main_chain.end(), sub_chain_element);
	main_chain.insert(it, sub_chain_element);
}

std::vector<int> PmergeMe::runMergeInsertionSort(const std::vector<int>& vec) {
	if (vec.size() < 2) {
		return (vec);
	}

	std::vector<std::vector<int> > pair_vec;
	std::size_t i = 0;
	while (i < vec.size()) {
		std::vector<int> tmp_vec;
		tmp_vec.push_back(vec[i++]);
		if (i < vec.size()) {
			tmp_vec.push_back(vec[i++]);
		} else {
			tmp_vec.push_back(-1);
			i++;
		}
		pair_vec.push_back(tmp_vec);
	}

	std::vector<int> larger_vec, smaller_vec;
	for (size_t i = 0; i < pair_vec.size(); ++i) {
		if (pair_vec[i][1] != -1 && pair_vec[i][0] < pair_vec[i][1]) {
			std::swap(pair_vec[i][0], pair_vec[i][1]);
		}
		larger_vec.push_back(pair_vec[i][0]);
		smaller_vec.push_back(pair_vec[i][1]);
	}

	std::vector<int> main_chain = runMergeInsertionSort(larger_vec);
	std::vector<unsigned int>jacobsthal_vec = createJacobstalIndex(smaller_vec);
	for (size_t i = 0; i < smaller_vec.size(); ++i) {
		unsigned int jacobsthal_index = jacobsthal_vec[i] - 1;
		if (smaller_vec[jacobsthal_index] != -1) {
			runBinaryInsertionSort(main_chain, smaller_vec[jacobsthal_index]);
		}
	}
	return (main_chain);
}

std::list<unsigned int>	PmergeMe::createJacobstalList(const size_t max_num) {
	std::list<unsigned int> jacobsthal_lst;
	for (size_t i = 0;; ++i) {
		unsigned int jacob_num = jacobsthal(i);
		if (jacob_num >= max_num) {
			jacobsthal_lst.push_back(max_num);
			break ;
		}
		jacobsthal_lst.push_back(jacob_num);
	}
	return (jacobsthal_lst);
}

std::list<unsigned int>	PmergeMe::createJacobstalIndex(const std::list<int>& smaller_lst) {
	std::list<unsigned int> jacobsthal_lst = createJacobstalList(smaller_lst.size());
	std::list<unsigned int> index_lst;
	std::list<unsigned int>::iterator it_i = jacobsthal_lst.begin();
	it_i++;
	for (; it_i != jacobsthal_lst.end(); ++it_i) {
		std::list<unsigned int>::iterator prev_it = it_i;
		prev_it--;
		for (unsigned int it_j = *it_i; it_j > *prev_it; --it_j) {
			index_lst.push_back(it_j);
		}
	}
	// for (size_t i = 1; i < jacobsthal_lst.size(); ++i) {
	// 	unsigned int prev_num = jacobsthal_lst[i - 1];
	// 	for (size_t j = jacobsthal_lst[i]; j > prev_num; --j) {
	// 		index_lst.push_back(j);
	// 	}
	// }
	// for (unsigned int i = 0; i < index_vec.size(); ++i) {
	// 	std::cout << index_vec[i] << ", ";
	// }
	// std::cout << std::endl;
	return (index_lst);
}

void	PmergeMe::runBinaryInsertionSort(std::list<int>& main_chain, const int sub_chain_element) {
	std::list<int>::iterator it = std::lower_bound(main_chain.begin(), main_chain.end(), sub_chain_element);
	main_chain.insert(it, sub_chain_element);
}

std::list<int> PmergeMe::runMergeInsertionSort(const std::list<int>& lst) {
	// std::cout << "=========================================" << std::endl;
	// std::cout << "start runMergeInsertionSort" << std::endl;
	if (lst.size() < 2) {
		// std::cout << "finish recursive!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << std::endl;
		return (lst);
	}

	std::list<std::pair<int, int> > pair_lst;
	std::list<int>::const_iterator it = lst.begin();
	while (it != lst.end()) {
		std::pair<int, int> tmp_pair;
		int first_element = *it++;
		if (it != lst.end()) {
			tmp_pair = std::make_pair(first_element, *it++);
		} else {
			tmp_pair = std::make_pair(first_element, -1);
		}
		// std::cout << tmp_pair.first << ", " << tmp_pair.second << std::endl;
		pair_lst.push_back(tmp_pair);
	}

	std::list<int> larger_lst, smaller_lst;
	for (std::list<std::pair<int, int> >::iterator it = pair_lst.begin(); it != pair_lst.end(); ++it) {
		if (it->second != -1 && it->first < it->second) {
			larger_lst.push_back(it->second);
			smaller_lst.push_back(it->first);
		} else {
			larger_lst.push_back(it->first);
			smaller_lst.push_back(it->second);
		}
	}
	// std::cout << "larger_lst: ";
	// for (std::list<int>::iterator it = larger_lst.begin(); it != larger_lst.end(); ++it) {
	// 	std::cout << *it << ", ";
	// }
	// std::cout << std::endl;
	// std::cout << "smaller_lst: ";
	// for (std::list<int>::iterator it = smaller_lst.begin(); it != smaller_lst.end(); ++it) {
	// 	std::cout << *it << ", ";
	// }
	// std::cout << std::endl;

	std::list<int> main_chain = runMergeInsertionSort(larger_lst);
	std::list<unsigned int>jacobsthal_lst = createJacobstalIndex(smaller_lst);
	// std::cout << "jacobsthal_lst: ";
	// for (std::list<unsigned int>::iterator it = jacobsthal_lst.begin(); it != jacobsthal_lst.end(); ++it) {
	// 	std::cout << *it << ", ";
	// }
	// std::cout << std::endl;
	for (std::list<unsigned int>::iterator it = jacobsthal_lst.begin(); it != jacobsthal_lst.end(); ++it) {
		int jacobsthal_index = *it - 1;
		std::list<int>::iterator jacobsthal_it = smaller_lst.begin();
		std::advance(jacobsthal_it, jacobsthal_index);
		if (*jacobsthal_it != -1) {
			runBinaryInsertionSort(main_chain, *jacobsthal_it);
		}
	}
	// std::cout << "main_chain: ";
	// for (std::list<int>::iterator it_j = main_chain.begin(); it_j != main_chain.end(); it_j++) {
	// 	std::cout << *it_j << ", ";
	// }
	// std::cout << std::endl;
	return (main_chain);
}

void	PmergeMe::printSortTime(const std::string& container, const double time, const size_t size) {
	std::cout << "Time to process a range of " << size << " elements with std::" << container << " : " << time << " us" << std::endl;
}

void	PmergeMe::sortVectorAndList() {
	// std::cout << "==============" << std::endl;
	// std::cout << "run sortMergeInsertion" << std::endl;
	printFirstSecondLine("Before: ");
	std::clock_t start_vec = std::clock();
	_vec = runMergeInsertionSort(_vec);
	std::clock_t end_vec = std::clock();
	std::clock_t start_lst = std::clock();
	_lst = runMergeInsertionSort(_lst);
	std::clock_t end_lst = std::clock();
	double time_vec = 1000000.0 * (static_cast<double>(end_vec) - static_cast<double>(start_vec)) / CLOCKS_PER_SEC;
	double time_lst = 1000000.0 * (static_cast<double>(end_lst) - static_cast<double>(start_lst)) / CLOCKS_PER_SEC;
	printFirstSecondLine("After: ");
	printSortTime("vector", time_vec, _vec.size());
	printSortTime("list", time_lst, _lst.size());
}

// void	PmergeMe::sortMergeInsertion() {
// 	// std::cout << "==============" << std::endl;
// 	// std::cout << "run sortMergeInsertion" << std::endl;
// 	printFirstSecondLine("Before: ");
// 	std::clock_t start_vec = std::clock();
// 	sortVector();
// 	std::clock_t end_vec = std::clock();
// 	// std::clock_t start_lst = std::clock();
// 	// sortList();
// 	// std::clock_t end_lst = std::clock();
// 	double time_vec = 1000000.0 * (static_cast<double>(end_vec) - static_cast<double>(start_vec)) / CLOCKS_PER_SEC;
// 	// double time_lst = 1000000.0 * (static_cast<double>(end_lst) - static_cast<double>(start_lst)) / CLOCKS_PER_SEC;
// 	printFirstSecondLine("After: ");
// 	printSortTime("vector", time_vec, _vec.size());
// 	// printSortTime("list", time_lst, _lst.size());
// }

// void	PmergeMe::insert(int sorted_index, const unsigned int element) {
// 	while (sorted_index >= 0) {
// 		if (element > _vec[sorted_index]) {
// 			break ;
// 		}
// 		_vec[sorted_index + 1] = _vec[sorted_index];
// 		sorted_index--;
// 	}
// 	_vec[sorted_index + 1] = element;
// }
// 
// void	PmergeMe::runInsertionSortVector() {
// 	for (size_t i = 1; i < _vec.size(); i++) {
// 		insert(i - 1, _vec[i]);
// 	}
// }
// 
// void	PmergeMe::mergeVector(int left, int middle, int right) {
// 	// std::cout << "merge" << std::endl;
// 	int left_index = left;
// 	int right_index = middle + 1;
// 	std::vector<unsigned int> tmp_vec;
// 
// 	while (left_index <= middle && right_index <= right) {
// 		if (_vec[left_index] < _vec[right_index]) {
// 			tmp_vec.push_back(_vec[left_index++]);
// 		} else {
// 			tmp_vec.push_back(_vec[right_index++]);
// 		}
// 	}
// 
// 	while (left_index <= middle) {
// 		tmp_vec.push_back(_vec[left_index++]);
// 	}
// 	while (right_index <= right) {
// 		tmp_vec.push_back(_vec[right_index++]);
// 	}
// 	for (int i = left; i <= right; i++) {
// 		_vec[i] = tmp_vec[i - left];
// 	}
// }
// 
// void	PmergeMe::runMergeSortVector(int left, int right) {
// 	if (left == right) {
// 		return ;
// 	}
// 	int middle = (right + left) / 2;
// 	// std::cout << "left: " << left << ", right: " << right << ", middle: " << middle << std::endl;
// 	runMergeSortVector(left, middle);
// 	runMergeSortVector(middle + 1, right);
// 	mergeVector(left, middle, right);
// }
// 
// void	PmergeMe::sortVector() {
// 	if (_vec.size() > 1700) {
// 		std::cout << "runMergeSortVector" << std::endl;
// 		runMergeSortVector(0, _vec.size() - 1);
// 	} else {
// 		std::cout << "runInsertionSortVector" << std::endl;
// 		runInsertionSortVector();
// 	}
// 	// for (size_t i = 0; i < _vec.size(); i++) {
// 	// 	std::cout << "vec[" << i << "]: " << _vec.at(i) << std::endl;
// 	// }
// }
// 
// void	PmergeMe::mergeList(std::list<unsigned int>::iterator left, std::list<unsigned int>::iterator middle, std::list<unsigned int>::iterator right) {
// 	// std::cout << "merge" << std::endl;
// 	std::list<unsigned int>::iterator left_it = left;
// 	std::list<unsigned int>::iterator right_it = middle;
// 	std::list<unsigned int> tmp_lst;
// 
// 	while (left_it != middle && right_it != right) {
// 		if (*left_it < *right_it) {
// 			tmp_lst.push_back(*left_it++);
// 		} else {
// 			tmp_lst.push_back(*right_it++);
// 		}
// 	}
// 
// 	while (left_it != middle) {
// 		tmp_lst.push_back(*left_it++);
// 	}
// 	while (right_it != right) {
// 		tmp_lst.push_back(*right_it++);
// 	}
// 	std::list<unsigned int>::iterator tmp_it = tmp_lst.begin();
// 	for (std::list<unsigned int>::iterator it = left; it != right; it++, tmp_it++) {
// 		*it = *tmp_it;
// 	}
// }
// 
// std::list<unsigned int>::iterator	PmergeMe::findMiddle(std::list<unsigned int>::iterator start, std::list<unsigned int>::iterator end) {
// 	std::list<unsigned int>::iterator first_step = start;
// 	std::list<unsigned int>::iterator second_step = start;
// 
// 	while (second_step != end && std::next(second_step) != end) {
// 		first_step = std::next(first_step);
// 		second_step = std::next(second_step);
// 		second_step = std::next(second_step);
// 	}
// 	return (first_step);
// }
// 
// void PmergeMe::runMergeSortList(std::list<unsigned int>::iterator left, std::list<unsigned int>::iterator right) {
// 	if (std::next(left) == right) {
// 		return ;
// 	}
// 	std::list<unsigned int>::iterator middle = findMiddle(left, right);
// 	runMergeSortList(left, middle);
// 	runMergeSortList(middle, right);
// 	mergeList(left, middle, right);
// }
// 
// void	PmergeMe::insert(std::list<unsigned int>::iterator sorted_index, const unsigned int element) {
// 	while (sorted_index != _lst.begin()) {
// 		if (element > *std::prev(sorted_index)) {
// 			break ;
// 		}
// 		*sorted_index = *std::prev(sorted_index);
// 		sorted_index--;
// 	}
// 	*sorted_index = element;
// }
// 
// void	PmergeMe::runInsertionSortList() {
// 	for (std::list<unsigned int>::iterator it = _lst.begin(); it != _lst.end(); it++) {
// 		insert(it, *it);
// 	}
// }
// 
// void	PmergeMe::sortList() {
// 	if (_lst.size() > 150) {
// 	     std::cout << "runMergeSortList" << std::endl;
// 	     runMergeSortList(_lst.begin(), _lst.end());
// 	} else {
// 	     std::cout << "runInsertionSortList" << std::endl;
// 	     runInsertionSortList();
// 	}
// 	// for (std::list<unsigned int>::iterator it = _lst.begin(); it != _lst.end(); it++) {
// 	// 	std::cout << "lst: " << *it << std::endl;
// 	// }
// }
