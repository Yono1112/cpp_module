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
	return (index_vec);
}

void	PmergeMe::runBinaryInsertionSort(std::vector<int>& main_chain, const int sub_chain_element) {
	std::vector<int>::iterator it = std::lower_bound(main_chain.begin(), main_chain.end(), sub_chain_element);
	main_chain.insert(it, sub_chain_element);
}

std::vector<int> PmergeMe::convertToPairVector(const std::vector<int>& vec) {
	std::vector<t_pair> pair_vec(vec.size());

	for (size_t i = 0; i < vec.size(); ++i) {
		pair_vec[i].num = vec[i];
	}
	for (size_t i = 0; i < pair_vec.size(); ++i) {
		std::cout << pair_vec[i].num << ", ";
	}
	std::cout << std::endl;

	// pair_vec[0].pair_vec.push_back(pair_vec[1]);
	// std::cout << pair_vec[0].pair_vec[0].num << std::endl;

	std::vector<t_pair> sorted_pair_vec = runMergeInsertionSort(pair_vec);
	std::vector<int> sorted_vec(vec.size());
	for (size_t i = 0; i < sorted_vec.size(); ++i) {
		sorted_vec[i] = sorted_pair_vec[i].num;
	}
	return (sorted_vec);
}

void printPairVec(const t_pair& pair, int depth = 0) {
	std::cout << std::string(depth, ' ') << "num: " << pair.num << std::endl;
	
	for (size_t i = 0; i < pair.pair_vec.size(); ++i) {
		printPairVec(pair.pair_vec[i], depth + 2);
	}
}

bool	PmergeMe::comp(const t_pair& first, const t_pair& second) {
	return (first.num < second.num);
}

void	PmergeMe::runBinaryInsertionSort(std::vector<t_pair>& main_chain, t_pair& insert_element, const size_t index) {
	// std::cout << "start runBinaryInsertionSort" << std::endl;
	std::cout << "insert_element: " << insert_element.num << ", main_chain[" << index << "]: " << main_chain[index].num << std::endl;
	// for (size_t i = 0; i < main_chain.size(); ++i) {
	// 	printPairVec(main_chain[i]);
	// }

	// std::cout << "0000000000000000000" << std::endl;
	std::vector<t_pair>::iterator it = std::lower_bound(main_chain.begin(), main_chain.begin() + index, insert_element, comp);
	// std::cout << "it: " << it->num << std::endl;
	main_chain.insert(it, insert_element);

	// for (size_t i = 0; i < main_chain.size(); ++i) {
	// 	printPairVec(main_chain[i]);
	// }
	// std::cout << "finish runBinaryInsertionSort" << std::endl;
}

std::vector<t_pair> PmergeMe::runMergeInsertionSort(std::vector<t_pair>& vec) {
	std::cout << "=================================================" << std::endl;
	if (vec.size() < 2) {
		return (vec);
	}

	std::vector<t_pair> recursive_vec;
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
	for (size_t i = 0; i < recursive_vec.size(); ++i) {
		printPairVec(recursive_vec[i]);
	}

	std::vector<t_pair> main_chain = runMergeInsertionSort(recursive_vec);

	std::cout << "main_chain---------------------------------------------" << std::endl;
	for (size_t i = 0; i < main_chain.size(); ++i) {
		printPairVec(main_chain[i]);
	}

	t_pair front = main_chain[0].pair_vec.back();
	main_chain[0].pair_vec.pop_back();
	// printPairVec(front);
	std::cout << "main_chain after insert index 0th ---------------------------------------------" << std::endl;
	if (front.num != -1) {
		main_chain.insert(main_chain.begin(), front);
	}
	for (size_t i = 0; i < main_chain.size(); ++i) {
		printPairVec(main_chain[i]);
	}

	for (size_t i = 1; i < main_chain.size(); ++i) {
		// if (vec.size() == main_chain.size()) {
		// 	break ;
		// }
		if (!main_chain[i].pair_vec.empty() && main_chain[0].pair_vec.size() < main_chain[i].pair_vec.size()) {
			t_pair insert_element = main_chain[i].pair_vec.back();
			main_chain[i].pair_vec.pop_back();
			if (insert_element.num != -1) {
				runBinaryInsertionSort(main_chain, insert_element, i);
				i++;
			}
		}
	}
	std::cout << "#############################################" << std::endl;
	for (size_t i = 0; i < main_chain.size(); ++i) {
		printPairVec(main_chain[i]);
	}
	std::cout << "#############################################" << std::endl;

	// std::exit(0);
	return (main_chain);
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
	return (index_lst);
}

void	PmergeMe::runBinaryInsertionSort(std::list<int>& main_chain, const int sub_chain_element) {
	std::list<int>::iterator it = std::lower_bound(main_chain.begin(), main_chain.end(), sub_chain_element);
	main_chain.insert(it, sub_chain_element);
}

std::list<int> PmergeMe::runMergeInsertionSort(const std::list<int>& lst) {
	if (lst.size() < 2) {
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

	std::list<int> main_chain = runMergeInsertionSort(larger_lst);

	std::list<unsigned int>jacobsthal_lst = createJacobstalIndex(smaller_lst);
	for (std::list<unsigned int>::iterator it = jacobsthal_lst.begin(); it != jacobsthal_lst.end(); ++it) {
		int jacobsthal_index = *it - 1;
		std::list<int>::iterator jacobsthal_it = smaller_lst.begin();
		std::advance(jacobsthal_it, jacobsthal_index);
		if (*jacobsthal_it != -1) {
			runBinaryInsertionSort(main_chain, *jacobsthal_it);
		}
	}

	return (main_chain);
}

void	PmergeMe::printSortTime(const std::string& container, const double time, const size_t size) {
	std::cout << "Time to process a range of " << size << " elements with std::" << container << " : " << time << " us" << std::endl;
}

void	PmergeMe::sortVectorAndList() {
	printFirstSecondLine("Before: ");
	std::clock_t start_vec = std::clock();
	// _vec = runMergeInsertionSort(_vec);
	_vec = convertToPairVector(_vec);
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
