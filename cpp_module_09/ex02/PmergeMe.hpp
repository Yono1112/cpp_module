#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <sstream>
#include <ctime>

typedef struct s_pair_vec {
	int		num;
	std::vector<struct s_pair_vec> pair_vec;
}	t_pair_vec;

typedef struct s_pair_lst {
	int		num;
	std::list<struct s_pair_lst> pair_lst;
}	t_pair_lst;

class PmergeMe {
	public:
		PmergeMe();
		PmergeMe(const PmergeMe& other);
		~PmergeMe();
		PmergeMe& operator=(const PmergeMe& other);
		void setVectorAndList(const char *str);
		void sortVectorAndList();
		static bool checkValidArgs(const char *str);
	private:
		unsigned int jacobsthal(const unsigned int n);
		void printFirstSecondLine(const std::string& str);
		void printSortTime(const std::string& container, const double time, const size_t size);
		// vector
		void createJacobstalVector(std::vector<unsigned int>& jacobsthal_vec, const size_t max_num);
		void createJacobstalIndex(std::vector<t_pair_vec>& index_pair_vec, std::vector<t_pair_vec>& main_chain);
		static bool compVec(const t_pair_vec& first, const t_pair_vec& second);
		void runBinaryInsertionSort(std::vector<t_pair_vec>& main_chain, t_pair_vec& insert_element);
		void insertFirstElement(std::vector<t_pair_vec>& main_chain);
		void createRecursiveVec(std::vector<t_pair_vec>& recursive_vec, std::vector<t_pair_vec> vec);
		void insertBasedOnJacobsthal(const std::vector<t_pair_vec>& jacobsthal_vec, std::vector<t_pair_vec>& main_chain);
		std::vector<t_pair_vec> runMergeInsertionSort(std::vector<t_pair_vec>& vec);
		// list
		void createJacobstalList(std::list<unsigned int>& jacobsthal_lst, const size_t max_num);
		void createJacobstalIndex(std::list<t_pair_lst>& index_pair_lst, std::list<t_pair_lst>& main_chain);
		static bool compLst(const t_pair_lst& first, const t_pair_lst& second);
		void runBinaryInsertionSort(std::list<t_pair_lst>& main_chain, t_pair_lst& insert_element);
		void insertBasedOnJacobsthal(const std::list<t_pair_lst>& jacobsthal_lst, std::list<t_pair_lst>& main_chain);
		void insertFirstElement(std::list<t_pair_lst>& main_chain, std::list<t_pair_lst>::iterator first);
		void createRecursiveLst(std::list<t_pair_lst>& recursive_lst, std::list<t_pair_lst> lst);
		std::list<t_pair_lst> runMergeInsertionSort(std::list<t_pair_lst>& lst);
	private:
		std::vector<t_pair_vec> _vec;
		std::list<t_pair_lst> _lst;
};

#endif
