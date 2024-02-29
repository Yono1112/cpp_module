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
		std::vector<unsigned int>	createJacobstalIndex(const std::vector<int>& smaller_vec);
		std::vector<unsigned int>	createJacobstalVector(const size_t max_num);
		unsigned int	jacobsthal(const unsigned int n);
		void printFirstSecondLine(const std::string& str);
		void printSortTime(const std::string& container, const double time, const size_t size);
		void runBinarySearch(std::vector<unsigned int>& vec, unsigned int num);
		std::vector<t_pair> runMergeInsertionSort(std::vector<t_pair>& vec);
		void runBinaryInsertionSort(std::vector<t_pair>& main_chain, t_pair& insert_element);
		static bool comp(const t_pair& first, const t_pair& second);
		std::vector<t_pair> createJacobstalIndex(std::vector<t_pair>& main_chain);
		void createRecursiveVec(std::vector<t_pair>& recursive_vec, std::vector<t_pair> vec);
		void insertFirstElement(std::vector<t_pair>& main_chain);
		void insertBasedOnJacobsthal(const std::vector<t_pair>& jacobsthal_vec, std::vector<t_pair>& main_chain);
		// list
		std::list<int> runMergeInsertionSort(const std::list<int>& lst);
		void	runBinaryInsertionSort(std::list<int>& main_chain, const int sub_chain_element);
		std::list<unsigned int>	createJacobstalIndex(const std::list<int>& smaller_lst);
		std::list<unsigned int>	createJacobstalList(const size_t max_num);
	private:
		// std::vector<int> _vec;
		std::vector<t_pair> _vec;
		std::list<int> _lst;
};

#endif
