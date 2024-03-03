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
		std::cout << _vec[i].num << " ";
	}
	std::cout << std::endl;
	std::cout << "std::lst " << str;
	for (std::list<t_pair_lst>::iterator it = _lst.begin(); it != _lst.end(); it++) {
		std::cout << it->num << " ";
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
		t_pair tmp_pair;
		tmp_pair.num = num;
		_vec.push_back(tmp_pair);

		t_pair_lst tmp_pair_lst;
		tmp_pair_lst.num = num;
		_lst.push_back(tmp_pair_lst);
	}
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

void	printPairVec(const t_pair& pair, int depth = 0) {
	std::cout << std::string(depth, ' ') << "num: " << pair.num << std::endl;
	
	for (size_t i = 0; i < pair.pair_vec.size(); ++i) {
		printPairVec(pair.pair_vec[i], depth + 2);
	}
}

std::vector<t_pair>	PmergeMe::createJacobstalIndex(std::vector<t_pair>& main_chain) {
	// std::cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << std::endl;
	std::vector<unsigned int> jacobsthal_vec = createJacobstalVector(main_chain.size() - 1);
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
	std::vector<t_pair> index_pair_vec;
	for (size_t i = 0; i < index_vec.size(); ++i) {
		t_pair tmp = main_chain[index_vec[i]];
		index_pair_vec.push_back(tmp);
		if (main_chain[0].pair_vec.size() < main_chain[index_vec[i]].pair_vec.size()) {
			main_chain[index_vec[i]].pair_vec.pop_back();
		}
	}
	// for (size_t i = 0; i < index_pair_vec.size(); ++i) {
	// 	printPairVec(index_pair_vec[i]);
	// }
	// std::cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << std::endl;
	return (index_pair_vec);
}

void	PmergeMe::runBinaryInsertionSort(std::vector<int>& main_chain, const int sub_chain_element) {
	std::vector<int>::iterator it = std::lower_bound(main_chain.begin(), main_chain.end(), sub_chain_element);
	main_chain.insert(it, sub_chain_element);
}

bool	PmergeMe::compVec(const t_pair& first, const t_pair& second) {
	return (first.num < second.num);
}

void	PmergeMe::runBinaryInsertionSort(std::vector<t_pair>& main_chain, t_pair& insert_element) {
	// std::cout << "start runBinaryInsertionSort" << std::endl;
	// std::cout << "insert_element: " << insert_element.num << ", main_chain[" << index << "]: " << main_chain[index].num << std::endl;
	// std::cout << "0000000000000000000" << std::endl;
	// for (size_t i = 0; i < main_chain.size(); ++i) {
	// 	printPairVec(main_chain[i]);
	// }
	// std::cout << "0000000000000000000" << std::endl;

	std::vector<t_pair>::iterator it = std::lower_bound(main_chain.begin() , main_chain.end(), insert_element, compVec);
	// std::cout << "it: " << it->num << std::endl;
	main_chain.insert(it, insert_element);

	// std::cout << "0000000000000000000" << std::endl;
	// for (size_t i = 0; i < main_chain.size(); ++i) {
	// 	printPairVec(main_chain[i]);
	// }
	// std::cout << "0000000000000000000" << std::endl;
	// std::cout << "finish runBinaryInsertionSort" << std::endl;
}

void	PmergeMe::createRecursiveVec(std::vector<t_pair>& recursive_vec, std::vector<t_pair> vec) {
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
			t_pair tmp;
			tmp.num = -1;
			vec[i].pair_vec.push_back(tmp);
			recursive_vec.push_back(vec[i]);
		}
	}
}

void	PmergeMe::insertFirstElement(std::vector<t_pair>& main_chain) {
	t_pair front = main_chain[0].pair_vec.back();
	main_chain[0].pair_vec.pop_back();
	if (front.num != -1) {
		main_chain.insert(main_chain.begin(), front);
	}
}

void	PmergeMe::insertBasedOnJacobsthal(const std::vector<t_pair>& jacobsthal_vec, std::vector<t_pair>& main_chain) {
	for (size_t i = 0; i < jacobsthal_vec.size() ; ++i) {
		// std::cout << "jacobsthal_vec.num: " << jacobsthal_vec[i].num << std::endl;
		if (!jacobsthal_vec[i].pair_vec.empty() && main_chain[0].pair_vec.size() < jacobsthal_vec[i].pair_vec.size()) {
			t_pair insert_element = jacobsthal_vec[i].pair_vec.back();
			// std::cout << "insert_element.num: " << insert_element.num << std::endl;
			if (insert_element.num != -1) {
				runBinaryInsertionSort(main_chain, insert_element);
			}
		}
	}
}

std::vector<t_pair> PmergeMe::runMergeInsertionSort(std::vector<t_pair>& vec) {
	// std::cout << "=================================================" << std::endl;
	if (vec.size() < 2) {
		return (vec);
	}

	std::vector<t_pair> recursive_vec;
	createRecursiveVec(recursive_vec, vec);
	// for (size_t i = 0; i < recursive_vec.size(); ++i) {
	// 	printPairVec(recursive_vec[i]);
	// }

	std::vector<t_pair> main_chain = runMergeInsertionSort(recursive_vec);

	// std::cout << "main_chain---------------------------------------------" << std::endl;
	// for (size_t i = 0; i < main_chain.size(); ++i) {
	// 	printPairVec(main_chain[i]);
	// }

	insertFirstElement(main_chain);
	// std::cout << "main_chain after insert index 0th ---------------------------------------------" << std::endl;
	// for (size_t i = 0; i < main_chain.size(); ++i) {
	// 	printPairVec(main_chain[i]);
	// }

	std::vector<t_pair>jacobsthal_vec = createJacobstalIndex(main_chain);
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

void	printPairLst(const t_pair_lst& pair, int depth = 0) {
	std::cout << std::string(depth, ' ') << "num: " << pair.num << std::endl;
	
	for (std::list<t_pair_lst>::const_iterator it = pair.pair_lst.begin(); it != pair.pair_lst.end(); ++it) {
		printPairLst(*it, depth + 2);
	}
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

std::list<t_pair_lst>	PmergeMe::createJacobstalIndex(std::list<t_pair_lst>& main_chain) {
	// std::cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << std::endl;
	std::list<unsigned int> jacobsthal_lst = createJacobstalList(main_chain.size() - 1);

	std::cout << "jacobsthal_lst: ";
	for (std::list<unsigned int>::iterator it = jacobsthal_lst.begin(); it != jacobsthal_lst.end(); ++it) {
		std::cout << *it << ", ";
	}
	std::cout << std::endl;

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

	std::cout << "index_lst: ";
	for (std::list<unsigned int>::iterator it = index_lst.begin(); it != index_lst.end(); ++it) {
		std::cout << *it << ", ";
	}
	std::cout << std::endl;

	std::list<t_pair_lst> index_pair_lst;
	for (std::list<unsigned int>::iterator index_it = index_lst.begin(); index_it != index_lst.end(); ++index_it) {
		std::list<t_pair_lst>::iterator main_it = main_chain.begin();
		std::advance(main_it, *index_it);
		index_pair_lst.push_back(*main_it);
		if (main_chain.front().pair_lst.size() < main_it->pair_lst.size()) {
			main_it->pair_lst.pop_back();
		}
	}
	// for (size_t i = 0; i < index_lst.size(); ++i) {
	// 	t_pair tmp = main_chain[index_lst[i]];
	// 	index_pair_lst.push_back(tmp);
	// 	if (main_chain[0].pair_lst.size() < main_chain[index_lst[i]].pair_lst.size()) {
	// 		main_chain[index_lst[i]].pair_lst.pop_back();
	// 	}
	// }
	for (std::list<t_pair_lst>::iterator it = main_chain.begin(); it != main_chain.end(); it++) {
		printPairLst(*it);
	}

	// std::cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << std::endl;
	// std::exit(0);
	return (index_pair_lst);
	// return (main_chain);
}

bool	PmergeMe::compLst(const t_pair_lst& first, const t_pair_lst& second) {
	return (first.num < second.num);
}

void	PmergeMe::runBinaryInsertionSort(std::list<t_pair_lst>& main_chain, t_pair_lst& insert_element) {
	// std::cout << "start runBinaryInsertionSort" << std::endl;
	// std::cout << "insert_element: " << insert_element.num << ", main_chain[" << index << "]: " << main_chain[index].num << std::endl;
	// std::cout << "0000000000000000000" << std::endl;
	// for (size_t i = 0; i < main_chain.size(); ++i) {
	// 	printPairVec(main_chain[i]);
	// }
	// std::cout << "0000000000000000000" << std::endl;

	std::list<t_pair_lst>::iterator it = std::lower_bound(main_chain.begin() , main_chain.end(), insert_element, compLst);
	// std::cout << "it: " << it->num << std::endl;
	main_chain.insert(it, insert_element);

	// std::cout << "0000000000000000000" << std::endl;
	// for (size_t i = 0; i < main_chain.size(); ++i) {
	// 	printPairVec(main_chain[i]);
	// }
	// std::cout << "0000000000000000000" << std::endl;
	// std::cout << "finish runBinaryInsertionSort" << std::endl;
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
		// main_chain.insert(main_chain.begin(), front);
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
	std::cout << "=================================================" << std::endl;
	if (lst.size() < 2) {
		return (lst);
	}

	std::list<t_pair_lst> recursive_lst;
	createRecursiveLst(recursive_lst, lst);
	for (std::list<t_pair_lst>::iterator it = recursive_lst.begin(); it != recursive_lst.end(); it++) {
		printPairLst(*it);
	}

	std::list<t_pair_lst> main_chain = runMergeInsertionSort(recursive_lst);

	std::cout << "main_chain---------------------------------------------" << std::endl;
	for (std::list<t_pair_lst>::iterator it = main_chain.begin(); it != main_chain.end(); it++) {
		printPairLst(*it);
	}

	std::cout << "main_chain after insert index 0th ---------------------------------------------" << std::endl;
	insertFirstElement(main_chain, main_chain.begin());
	for (std::list<t_pair_lst>::iterator it = main_chain.begin(); it != main_chain.end(); it++) {
		printPairLst(*it);
	}

	std::list<t_pair_lst> jacobsthal_lst = createJacobstalIndex(main_chain);
	if (!jacobsthal_lst.empty()) {
		insertBasedOnJacobsthal(jacobsthal_lst, main_chain);
	}
	std::cout << "#############################################" << std::endl;
	for (std::list<t_pair_lst>::iterator it = main_chain.begin(); it != main_chain.end(); it++) {
		printPairLst(*it);
	}
	std::cout << "#############################################" << std::endl;
	// std::exit(0);

	return (main_chain);
}

// void	PmergeMe::runBinaryInsertionSort(std::list<int>& main_chain, const int sub_chain_element) {
// 	std::list<int>::iterator it = std::lower_bound(main_chain.begin(), main_chain.end(), sub_chain_element);
// 	main_chain.insert(it, sub_chain_element);
// }

// std::list<int> PmergeMe::runMergeInsertionSort(const std::list<int>& lst) {
// 	if (lst.size() < 2) {
// 		return (lst);
// 	}
// 
// 	std::list<std::pair<int, int> > pair_lst;
// 	std::list<int>::const_iterator it = lst.begin();
// 	while (it != lst.end()) {
// 		std::pair<int, int> tmp_pair;
// 		int first_element = *it++;
// 		if (it != lst.end()) {
// 			tmp_pair = std::make_pair(first_element, *it++);
// 		} else {
// 			tmp_pair = std::make_pair(first_element, -1);
// 		}
// 		pair_lst.push_back(tmp_pair);
// 	}
// 
// 	std::list<int> larger_lst, smaller_lst;
// 	for (std::list<std::pair<int, int> >::iterator it = pair_lst.begin(); it != pair_lst.end(); ++it) {
// 		if (it->second != -1 && it->first < it->second) {
// 			larger_lst.push_back(it->second);
// 			smaller_lst.push_back(it->first);
// 		} else {
// 			larger_lst.push_back(it->first);
// 			smaller_lst.push_back(it->second);
// 		}
// 	}
// 
// 	std::list<int> main_chain = runMergeInsertionSort(larger_lst);
// 
// 	std::list<unsigned int>jacobsthal_lst = createJacobstalIndex(smaller_lst);
// 	for (std::list<unsigned int>::iterator it = jacobsthal_lst.begin(); it != jacobsthal_lst.end(); ++it) {
// 		int jacobsthal_index = *it - 1;
// 		std::list<int>::iterator jacobsthal_it = smaller_lst.begin();
// 		std::advance(jacobsthal_it, jacobsthal_index);
// 		if (*jacobsthal_it != -1) {
// 			runBinaryInsertionSort(main_chain, *jacobsthal_it);
// 		}
// 	}
// 
// 	return (main_chain);
// }

void	PmergeMe::printSortTime(const std::string& container, const double time, const size_t size) {
	std::cout << "Time to process a range of " << size << " elements with std::" << container << " : " << time << " us" << std::endl;
}

void	PmergeMe::sortVectorAndList() {
	printFirstSecondLine("Before: ");
	std::clock_t start_vec = std::clock();
	_vec = runMergeInsertionSort(_vec);
	// _vec = convertToPairVector(_vec);
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
