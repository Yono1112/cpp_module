#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <string>
#include <list>
#include <vector>

class PmergeMe {
	public:
		PmergeMe();
		PmergeMe(const PmergeMe& other);
		~PmergeMe();
		PmergeMe& operator=(const PmergeMe& other);
		static bool checkValidArgs(const char *str);
	private:
		std::vector<unsigned int> _vec;
		std::list<unsigned int> _lst;
};

#endif
