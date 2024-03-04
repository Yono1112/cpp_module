#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <sstream>
#include <ctime>

typedef struct s_pair {
	int		num;
	std::vector<struct s_pair> pair_vec;
}	t_pair;

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
		// vector
		void	runBinaryInsertionSort(std::vector<int>& main_chain, const int sub_chain_element);
		// std::vector<unsigned int>	createJacobstalIndex(const std::vector<int>& smaller_vec);
		std::vector<unsigned int>	createJacobstalVector(const size_t max_num);
		unsigned int	jacobsthal(const unsigned int n);
		void printFirstSecondLine(const std::string& str);
		void printSortTime(const std::string& container, const double time, const size_t size);
		void runBinarySearch(std::vector<unsigned int>& vec, unsigned int num);
		std::vector<t_pair> runMergeInsertionSort(std::vector<t_pair>& vec);
		void runBinaryInsertionSort(std::vector<t_pair>& main_chain, t_pair& insert_element);
		static bool compVec(const t_pair& first, const t_pair& second);
		std::vector<t_pair> createJacobstalIndex(std::vector<t_pair>& main_chain);
		void createRecursiveVec(std::vector<t_pair>& recursive_vec, std::vector<t_pair> vec);
		void insertFirstElement(std::vector<t_pair>& main_chain);
		void insertBasedOnJacobsthal(const std::vector<t_pair>& jacobsthal_vec, std::vector<t_pair>& main_chain);
		// list
		std::list<int> runMergeInsertionSort(const std::list<int>& lst);
		void	runBinaryInsertionSort(std::list<int>& main_chain, const int sub_chain_element);

		static bool compLst(const t_pair_lst& first, const t_pair_lst& second);
		void runBinaryInsertionSort(std::list<t_pair_lst>& main_chain, t_pair_lst& insert_element);
		void insertBasedOnJacobsthal(const std::list<t_pair_lst>& jacobsthal_lst, std::list<t_pair_lst>& main_chain);
		void createJacobstalList(std::list<unsigned int>& jacobsthal_lst, const size_t max_num);
		std::list<t_pair_lst> createJacobstalIndex(std::list<t_pair_lst>& main_chain);
		void createJacobstalIndex(std::list<t_pair_lst>& index_pair_lst, std::list<t_pair_lst>& main_chain);
		void insertFirstElement(std::list<t_pair_lst>& main_chain, std::list<t_pair_lst>::iterator first);
		void createRecursiveLst(std::list<t_pair_lst>& recursive_lst, std::list<t_pair_lst> lst);
		std::list<t_pair_lst> runMergeInsertionSort(std::list<t_pair_lst>& lst);
	private:
		// std::vector<int> _vec;
		std::vector<t_pair> _vec;
		std::list<t_pair_lst> _lst;
};

#endif
