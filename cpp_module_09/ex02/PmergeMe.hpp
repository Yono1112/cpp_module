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
		void printSortTime(const std::string& container, const double time, const size_t size);
		// vector
		void sortVector();
		void mergeVector(int left, int middle, int right);
		void runMergeSortVector(int left, int right);
		void insert(int sorted_index, const unsigned int element);
		void runInsertionSortVector();
		// list
		void sortList();
		void mergeList(std::list<unsigned int>::iterator left, std::list<unsigned int>::iterator middle, std::list<unsigned int>::iterator right);
		std::list<unsigned int>::iterator findMiddle(std::list<unsigned int>::iterator start, std::list<unsigned int>::iterator end);
		void runMergeSortList(std::list<unsigned int>::iterator left, std::list<unsigned int>::iterator right);
		void insert(std::list<unsigned int>::iterator sorted_index, const unsigned int element);
		void runInsertionSortList();
	private:
		std::vector<unsigned int> _vec;
		std::list<unsigned int> _lst;
};

#endif
