#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <sstream>
#include <ctime>

class PmergeMe {
	public:
		PmergeMe();
		PmergeMe(const PmergeMe& other);
		~PmergeMe();
		PmergeMe& operator=(const PmergeMe& other);
		void setVectorAndList(const char *str);
		void sortMergeInsertion();
		static bool checkValidArgs(const char *str);
	private:
		void printFirstSecondLine(const std::string& str);
		void sortVector();
		void insert(int sorted_index, const unsigned int element);
		void insert(std::list<unsigned int>::iterator sorted_index, const unsigned int element);
		void sortList();
	private:
		std::vector<unsigned int> _vec;
		std::list<unsigned int> _lst;
};

#endif
