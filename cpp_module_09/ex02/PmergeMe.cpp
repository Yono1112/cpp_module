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

bool	PmergeMe::checkValidArgs(const int argc, const char **str) {
	for (int i = 1; i < argc; ++i) {
		for (size_t j = 0; str[i][j]; ++j) {
			if (!std::isdigit(str[i][j]) && str[i][j] != ' ') {
				return (false);
			}
		}
	}
	return (true);
}

void	PmergeMe::printFirstSecondLine(const std::string& str) {
	// std::cout << "std::vec " << str;
	std::cout << str;
	for (size_t i = 0; i < _vec.size(); i++) {
		std::cout << _vec[i].num << " ";
	}
	std::cout << std::endl;
	// std::cout << "std::lst " << str;
	// for (std::list<t_pair_lst>::iterator it = _lst.begin(); it != _lst.end(); it++) {
	// 	std::cout << it->num << " ";
	// }
	// std::cout << std::endl;
}

void	PmergeMe::setVectorAndList(const int argc, const char **c_str) {
	for (int i = 1; i < argc; ++i) {
		std::string str(c_str[i]);
		std::istringstream iss(str);
		long num;

		while (iss >> num) {
			if (std::numeric_limits<int>::max() < num || std::numeric_limits<int>::min() > num) {
				throw std::out_of_range("int out of range");
			}
			t_pair_vec tmp_pair;
			tmp_pair.num = num;
			_vec.push_back(tmp_pair);

			t_pair_lst tmp_pair_lst;
			tmp_pair_lst.num = num;
			_lst.push_back(tmp_pair_lst);
		}
	}
}

void	PmergeMe::printSortTime(const std::string& container, const double time, const size_t size) {
	std::cout << "Time to process a range of " << size << " elements with std::" << container << " : " << time << " us" << std::endl;
}

void	PmergeMe::sortVectorAndList() {
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

// Implementation of mergeInsertionSort in std::vector

void	PmergeMe::createJacobstalVector(std::vector<unsigned int>& jacobsthal_vec, const size_t max_num) {
	for (size_t i = 0;; ++i) {
		unsigned int jacob_num = jacobsthal(i);
		if (jacob_num >= max_num) {
			jacobsthal_vec.push_back(max_num);
			break ;
		}
		jacobsthal_vec.push_back(jacob_num);
	}
}

void	printPairVec(const t_pair_vec& pair, int depth = 0) {
	std::cout << std::string(depth, ' ') << "num: " << pair.num << std::endl;
	
	for (size_t i = 0; i < pair.pair_vec.size(); ++i) {
		printPairVec(pair.pair_vec[i], depth + 2);
	}
}

void	PmergeMe::createJacobstalIndex(std::vector<t_pair_vec>& index_pair_vec, std::vector<t_pair_vec>& main_chain) {
	std::vector<unsigned int> jacobsthal_vec;
	createJacobstalVector(jacobsthal_vec, main_chain.size() - 1);

	// std::cout << "jacobsthal_vec: ";
	// for (size_t i = 0; i < jacobsthal_vec.size(); ++i) {
	// 	std::cout << jacobsthal_vec[i] << ", ";
	// }
	// std::cout << std::endl;

	std::vector<unsigned int> index_vec;
	for (size_t i = 1; i < jacobsthal_vec.size(); ++i) {
		unsigned int prev_num = jacobsthal_vec[i - 1];
		for (unsigned int j = jacobsthal_vec[i]; j > prev_num; --j) {
			index_vec.push_back(j);
		}
	}

	// std::cout << "index_vec: ";
	// for (size_t i = 0; i < index_vec.size(); ++i) {
	// 	std::cout << index_vec[i] << ", ";
	// }
	// std::cout << std::endl;

	for (size_t i = 0; i < index_vec.size(); ++i) {
		t_pair_vec tmp = main_chain[index_vec[i]];
		index_pair_vec.push_back(tmp);
		if (main_chain[0].pair_vec.size() < main_chain[index_vec[i]].pair_vec.size()) {
			main_chain[index_vec[i]].pair_vec.pop_back();
		}
	}

	// for (size_t i = 0; i < index_pair_vec.size(); ++i) {
	// 	printPairVec(index_pair_vec[i]);
	// }
}

bool	PmergeMe::compVec(const t_pair_vec& first, const t_pair_vec& second) {
	return (first.num < second.num);
}

void	PmergeMe::runBinaryInsertionSort(std::vector<t_pair_vec>& main_chain, t_pair_vec& insert_element) {
	std::vector<t_pair_vec>::iterator it = std::lower_bound(main_chain.begin() , main_chain.end(), insert_element, compVec);
	main_chain.insert(it, insert_element);
}

void	PmergeMe::createRecursiveVec(std::vector<t_pair_vec>& recursive_vec, std::vector<t_pair_vec> vec) {
	for (size_t i = 0; i < vec.size(); i += 2) {
		if (i + 1 < vec.size()) {
			if (vec[i].num > vec[i + 1].num) {
				vec[i].pair_vec.push_back(vec[i + 1]);
				recursive_vec.push_back(vec[i]);
			} else {
				vec[i + 1].pair_vec.push_back(vec[i]);
				recursive_vec.push_back(vec[i + 1]);
			}
		} else {
			t_pair_vec tmp;
			tmp.num = -1;
			vec[i].pair_vec.push_back(tmp);
			recursive_vec.push_back(vec[i]);
		}
	}
}

void	PmergeMe::insertFirstElement(std::vector<t_pair_vec>& main_chain) {
	t_pair_vec front = main_chain[0].pair_vec.back();
	main_chain[0].pair_vec.pop_back();
	if (front.num != -1) {
		main_chain.insert(main_chain.begin(), front);
	}
}

void	PmergeMe::insertBasedOnJacobsthal(const std::vector<t_pair_vec>& jacobsthal_vec, std::vector<t_pair_vec>& main_chain) {
	for (size_t i = 0; i < jacobsthal_vec.size() ; ++i) {
		if (!jacobsthal_vec[i].pair_vec.empty() && main_chain[0].pair_vec.size() < jacobsthal_vec[i].pair_vec.size()) {
			t_pair_vec insert_element = jacobsthal_vec[i].pair_vec.back();
			if (insert_element.num != -1) {
				runBinaryInsertionSort(main_chain, insert_element);
			}
		}
	}
}

std::vector<t_pair_vec> PmergeMe::runMergeInsertionSort(std::vector<t_pair_vec>& vec) {
	// std::cout << "=================================================" << std::endl;
	if (vec.size() < 2) {
		return (vec);
	}

	std::vector<t_pair_vec> recursive_vec;
	createRecursiveVec(recursive_vec, vec);
	// for (size_t i = 0; i < recursive_vec.size(); ++i) {
	// 	printPairVec(recursive_vec[i]);
	// }

	std::vector<t_pair_vec> main_chain = runMergeInsertionSort(recursive_vec);

	// std::cout << "main_chain---------------------------------------------" << std::endl;
	// for (size_t i = 0; i < main_chain.size(); ++i) {
	// 	printPairVec(main_chain[i]);
	// }

	insertFirstElement(main_chain);
	// std::cout << "main_chain after insert index 0th ---------------------------------------------" << std::endl;
	// for (size_t i = 0; i < main_chain.size(); ++i) {
	// 	printPairVec(main_chain[i]);
	// }

	std::vector<t_pair_vec> jacobsthal_vec;
	createJacobstalIndex(jacobsthal_vec, main_chain);
	if (!jacobsthal_vec.empty()) {
		insertBasedOnJacobsthal(jacobsthal_vec, main_chain);
	}
	// std::cout << "#############################################" << std::endl;
	// for (size_t i = 0; i < main_chain.size(); ++i) {
	// 	printPairVec(main_chain[i]);
	// }
	// std::cout << "#############################################" << std::endl;

	return (main_chain);
}

// Implementation of mergeInsertionSort in std::list

void	printPairLst(const t_pair_lst& pair, int depth = 0) {
	std::cout << std::string(depth, ' ') << "num: " << pair.num << std::endl;
	
	for (std::list<t_pair_lst>::const_iterator it = pair.pair_lst.begin(); it != pair.pair_lst.end(); ++it) {
		printPairLst(*it, depth + 2);
	}
}

void	PmergeMe::createJacobstalList(std::list<unsigned int>& jacobsthal_lst, const size_t max_num) {
	for (size_t i = 0;; ++i) {
		unsigned int jacob_num = jacobsthal(i);
		if (jacob_num >= max_num) {
			jacobsthal_lst.push_back(max_num);
			break ;
		}
		jacobsthal_lst.push_back(jacob_num);
	}
}

void	PmergeMe::createJacobstalIndex(std::list<t_pair_lst>& index_pair_lst, std::list<t_pair_lst>& main_chain) {
	std::list<unsigned int> jacobsthal_lst;
	createJacobstalList(jacobsthal_lst, main_chain.size() - 1);

	// std::cout << "jacobsthal_lst: ";
	// for (std::list<unsigned int>::iterator it = jacobsthal_lst.begin(); it != jacobsthal_lst.end(); ++it) {
	// 	std::cout << *it << ", ";
	// }
	// std::cout << std::endl;

	std::list<unsigned int> index_lst;
	std::list<unsigned int>::iterator it = jacobsthal_lst.begin();
	unsigned int prev_num = *it++;
	while (it != jacobsthal_lst.end()) {
		unsigned int current_num = *it;
		for (unsigned int i = current_num; i > prev_num; --i) {
			index_lst.push_back(i);
		}
		prev_num = current_num;
		it++;
	}

	// std::cout << "index_lst: ";
	// for (std::list<unsigned int>::iterator it = index_lst.begin(); it != index_lst.end(); ++it) {
	// 	std::cout << *it << ", ";
	// }
	// std::cout << std::endl;

	for (std::list<unsigned int>::iterator index_it = index_lst.begin(); index_it != index_lst.end(); ++index_it) {
		std::list<t_pair_lst>::iterator main_it = main_chain.begin();
		std::advance(main_it, *index_it);
		index_pair_lst.push_back(*main_it);
		if (main_chain.front().pair_lst.size() < main_it->pair_lst.size()) {
			main_it->pair_lst.pop_back();
		}
	}
	// for (std::list<t_pair_lst>::iterator it = main_chain.begin(); it != main_chain.end(); it++) {
	// 	printPairLst(*it);
	// }
}

bool	PmergeMe::compLst(const t_pair_lst& first, const t_pair_lst& second) {
	return (first.num < second.num);
}

void	PmergeMe::runBinaryInsertionSort(std::list<t_pair_lst>& main_chain, t_pair_lst& insert_element) {
	std::list<t_pair_lst>::iterator it = std::lower_bound(main_chain.begin() , main_chain.end(), insert_element, compLst);
	main_chain.insert(it, insert_element);

}

void	PmergeMe::createRecursiveLst(std::list<t_pair_lst>& recursive_lst, std::list<t_pair_lst> lst) {
	std::list<t_pair_lst>::iterator it = lst.begin();
	while (it != lst.end()) {
		t_pair_lst first = *it;
		it++;
		if (it != lst.end()) {
			t_pair_lst second = *it;
			if (first.num > second.num) {
				first.pair_lst.push_back(second);
				recursive_lst.push_back(first);
			} else {
				second.pair_lst.push_back(first);
				recursive_lst.push_back(second);
			}
			++it;
		} else {
			t_pair_lst tmp;
			tmp.num = -1;
			first.pair_lst.push_back(tmp);
			recursive_lst.push_back(first);
		}
	}
}

void	PmergeMe::insertFirstElement(std::list<t_pair_lst>& main_chain, std::list<t_pair_lst>::iterator first) {
	t_pair_lst front = first->pair_lst.back();
	first->pair_lst.pop_back();
	if (front.num != -1) {
		main_chain.push_front(front);
	}
}

void	PmergeMe::insertBasedOnJacobsthal(const std::list<t_pair_lst>& jacobsthal_lst, std::list<t_pair_lst>& main_chain) {
	for (std::list<t_pair_lst>::const_iterator it = jacobsthal_lst.begin(); it != jacobsthal_lst.end(); ++it) {
		if (!it->pair_lst.empty() && main_chain.front().pair_lst.size() < it->pair_lst.size()) {
			t_pair_lst insert_element = it->pair_lst.back();
			if (insert_element.num != -1) {
				runBinaryInsertionSort(main_chain, insert_element);
			}
		}
	}
}

std::list<t_pair_lst> PmergeMe::runMergeInsertionSort(std::list<t_pair_lst>& lst) {
	// std::cout << "=================================================" << std::endl;
	if (lst.size() < 2) {
		return (lst);
	}

	std::list<t_pair_lst> recursive_lst;
	createRecursiveLst(recursive_lst, lst);
	// for (std::list<t_pair_lst>::iterator it = recursive_lst.begin(); it != recursive_lst.end(); it++) {
	// 	printPairLst(*it);
	// }

	std::list<t_pair_lst> main_chain = runMergeInsertionSort(recursive_lst);

	// std::cout << "main_chain---------------------------------------------" << std::endl;
	// for (std::list<t_pair_lst>::iterator it = main_chain.begin(); it != main_chain.end(); it++) {
	// 	printPairLst(*it);
	// }

	insertFirstElement(main_chain, main_chain.begin());
	// std::cout << "main_chain after insert index 0th ---------------------------------------------" << std::endl;
	// for (std::list<t_pair_lst>::iterator it = main_chain.begin(); it != main_chain.end(); it++) {
	// 	printPairLst(*it);
	// }

	std::list<t_pair_lst> jacobsthal_lst;
	createJacobstalIndex(jacobsthal_lst, main_chain);
	if (!jacobsthal_lst.empty()) {
		insertBasedOnJacobsthal(jacobsthal_lst, main_chain);
	}
	// std::cout << "#############################################" << std::endl;
	// for (std::list<t_pair_lst>::iterator it = main_chain.begin(); it != main_chain.end(); it++) {
	// 	printPairLst(*it);
	// }
	// std::cout << "#############################################" << std::endl;

	return (main_chain);
}
