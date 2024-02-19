#include "PmergeMe.hpp"

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

// unsigned int	jacobsthal(const unsigned int n) {
// 	if (n == 0) {
// 		return (0);
// 	} else if (n == 1) {
// 		return (1);
// 	}
// 	std::vector<unsigned int> jacobsthal_nums(n + 1);
// 	jacobsthal_nums[0] = 0;
// 	jacobsthal_nums[1] = 1;
// 	for (unsigned int i = 2; i <= n; ++i) {
// 		jacobsthal_nums[i] = jacobsthal_nums[i - 1] + 2 * jacobsthal_nums[i - 2];
// 	}
// 	return (jacobsthal_nums[n]);
// }
// 
// std::vector<unsigned int>	createJacobstalVector(const size_t max_num) {
// 	std::vector<unsigned int> jacobsthal_vec;
// 	for (size_t i = 0;; ++i) {
// 		unsigned int jacob_num = jacobsthal(i);
// 		if (jacob_num >= max_num) {
// 			jacobsthal_vec.push_back(max_num);
// 			break ;
// 		}
// 		jacobsthal_vec.push_back(jacob_num);
// 	}
// 	return (jacobsthal_vec);
// }
// 
// std::vector<unsigned int>	createJacobstalIndex(const std::vector<int>& smaller_vec) {
// 	std::vector<unsigned int> jacobsthal_vec = createJacobstalVector(smaller_vec.size());
// 	std::vector<unsigned int> index_vec;
// 	for (size_t i = 1; i < jacobsthal_vec.size(); ++i) {
// 		unsigned int prev_num = jacobsthal_vec[i - 1];
// 		for (size_t j = jacobsthal_vec[i]; j > prev_num; --j) {
// 			index_vec.push_back(j);
// 		}
// 	}
// 	// for (unsigned int i = 0; i < index_vec.size(); ++i) {
// 	// 	std::cout << index_vec[i] << ", ";
// 	// }
// 	// std::cout << std::endl;
// 	return (index_vec);
// }
// 
// void	runBinaryInsertionSort(std::vector<int>& main_chain, const int sub_chain_element) {
// 	std::vector<int>::iterator it = std::lower_bound(main_chain.begin(), main_chain.end(), sub_chain_element);
// 	main_chain.insert(it, sub_chain_element);
// }
// 
// std::vector<int> runMergeInsersionSort(const std::vector<int>& vec) {
// 	// std::cout << "start sortRecursively" << std::endl;
// 	if (vec.size() < 2) {
// 		return vec;
// 	}
// 
// 	std::vector<std::vector<int> > pair_vec;
// 	std::size_t i = 0;
// 	while (i < vec.size()) {
// 		std::vector<int> tmp_vec;
// 		tmp_vec.push_back(vec[i++]);
// 		if (i < vec.size()) {
// 			tmp_vec.push_back(vec[i++]);
// 		} else {
// 			tmp_vec.push_back(-1);
// 			i++;
// 		}
// 		pair_vec.push_back(tmp_vec);
// 	}
// 
// 	// for (size_t i = 0; i < pair_vec.size(); ++i) {
// 	//     std::cout << "(" << pair_vec[i][0];
// 	//     std::cout << ", " << pair_vec[i][1];
// 	//     std::cout << ") ";
// 	// }
// 	// std::cout << std::endl;
// 
// 	std::vector<int> larger_vec, smaller_vec;
// 	for (size_t i = 0; i < pair_vec.size(); ++i) {
// 		if (pair_vec[i][1] != -1 && pair_vec[i][0] < pair_vec[i][1]) {
// 			std::swap(pair_vec[i][0], pair_vec[i][1]);
// 		}
// 		larger_vec.push_back(pair_vec[i][0]);
// 		smaller_vec.push_back(pair_vec[i][1]);
// 	}
// 
// 	// for (size_t i = 0; i < pair_vec.size(); ++i) {
// 	//     std::cout << "(" << pair_vec[i][0];
// 	//     std::cout << ", " << pair_vec[i][1];
// 	//     std::cout << ") ";
// 	// }
// 	// std::cout << std::endl;
// 
// 	// for (size_t i = 0; i < larger_vec.size(); ++i) {
// 	// 	std::cout << larger_vec[i] << ", ";
// 	// }
// 	// std::cout << std::endl;
// 	
// 	std::vector<int> main_chain = runMergeInsertionSort(larger_vec);
// 	// std::cout << "===========================" << std::endl;
// 	std::vector<unsigned int>jacobsthal_vec = createJacobstalIndex(smaller_vec);
// 	// std::cout << "jacobsthal_vec: ";
// 	// for (size_t i = 0; i < jacobsthal_vec.size(); ++i) {
// 	// 	std::cout << jacobsthal_vec[i] << ", ";
// 	// }
// 	// std::cout << std::endl;
// 	// std::cout << "smaller_vec: ";
// 	// for (size_t i = 0; i < smaller_vec.size(); ++i) {
// 	// 	std::cout << smaller_vec[i] << ", ";
// 	// }
// 	// std::cout << std::endl;
// 	// std::cout << "main_chain: ";
// 	// for (size_t i = 0; i < main_chain.size(); ++i) {
// 	// 	std::cout << main_chain[i] << ", ";
// 	// }
// 	// std::cout << std::endl;
// 	for (size_t i = 0; i < smaller_vec.size(); ++i) {
// 		unsigned int jacobsthal_index = jacobsthal_vec[i] - 1;
// 		// std::cout << "jacobsthal_index: " << jacobsthal_index << std::endl;
// 		if (smaller_vec[jacobsthal_index] != -1) {
// 			runBinaryInsertionSort(main_chain, smaller_vec[jacobsthal_index]);
// 		}
// 	}
// 	// std::cout << "main_chain: ";
// 	// for (size_t i = 0; i < main_chain.size(); ++i) {
// 	// 	std::cout << main_chain[i] << ", ";
// 	// }
// 	// std::cout << std::endl;
// 	// for (size_t i = 0; i < smaller_vec.size(); ++i) {
// 	// 	if (smaller_vec[i] != -1) {
// 	// 		runBinaryInsertionSort(main_chain, smaller_vec[i]);
// 	// 	}
// 	// }
// 	return (main_chain);
// }
// 
// std::vector<int> sortRecursivelyNotJacob(const std::vector<int>& vec) {
// 	if (vec.size() < 2) {
// 		return vec;
// 	}
// 	std::vector<std::vector<int> > pair_vec;
// 	std::size_t i = 0;
// 	while (i < vec.size()) {
// 		std::vector<int> tmp_vec;
// 		tmp_vec.push_back(vec[i++]);
// 		if (i < vec.size()) {
// 			tmp_vec.push_back(vec[i++]);
// 		} else {
// 			tmp_vec.push_back(-1);
// 			i++;
// 		}
// 		pair_vec.push_back(tmp_vec);
// 	}
// 	std::vector<int> larger_vec, smaller_vec;
// 	for (size_t i = 0; i < pair_vec.size(); ++i) {
// 		if (pair_vec[i][1] != -1 && pair_vec[i][0] < pair_vec[i][1]) {
// 			std::swap(pair_vec[i][0], pair_vec[i][1]);
// 		}
// 		larger_vec.push_back(pair_vec[i][0]);
// 		smaller_vec.push_back(pair_vec[i][1]);
// 	}
// 
// 	std::vector<int> main_chain = sortRecursively(larger_vec);
// 	std::vector<unsigned int>jacobsthal_vec = createJacobstalIndex(smaller_vec);
// 	for (size_t i = 0; i < smaller_vec.size(); ++i) {
// 		if (smaller_vec[i] != -1) {
// 			runBinaryInsertionSort(main_chain, smaller_vec[i]);
// 		}
// 	}
// 	return (main_chain);
// }

#include <ctime>
#include <cstdlib>
int main(int argc, char **argv) {
	// int arr[] = {5, 12, 8, 10, 3, 7, 6, 4, 9, 2, 1, 11, 13};
	// int arr[];
	// std::vector<int> vec1, vec2;
	// srand(time(NULL));
	// for (size_t i = 0; i < 5000; ++i) {
	// 	int num = rand() % 10000 + 1;
	// 	vec1.push_back(num);
	// 	vec2.push_back(num);
	// }
	// size_t arr_size = sizeof(arr) / sizeof(arr[0]);
	// int arr[] = {1, 1, 1, 1};
	// std::vector<int> vec(arr, arr + arr_size);
	if (argc != 2 || !PmergeMe::checkValidArgs(argv[1])) {
		std::cerr << "Error" << std::endl;
		return (1);
	}
	PmergeMe arr;
	arr.setVectorAndList(argv[1]);
	arr.sortVectorAndList();

	// std::clock_t start_vec1 = std::clock();
	// std::vector<int> sorted_vec1 = sortRecursively(vec1);
	// std::clock_t end_vec1 = std::clock();
	// double time_vec1 = 1000000.0 * (static_cast<double>(end_vec1) - static_cast<double>(start_vec1)) / CLOCKS_PER_SEC;
	// // double time_vec1 = (static_cast<double>(end_vec1) - static_cast<double>(start_vec1)) / CLOCKS_PER_SEC;
	// std::cout << "sort time jacob: " << time_vec1 << std::endl;

	// std::clock_t start_vec2 = std::clock();
	// std::vector<int> sorted_vec2 = sortRecursivelyNotJacob(vec2);
	// std::clock_t end_vec2 = std::clock();
	// double time_vec2 = 1000000.0 * (static_cast<double>(end_vec2) - static_cast<double>(start_vec2)) / CLOCKS_PER_SEC;
	// // double time_vec2 = (static_cast<double>(end_vec2) - static_cast<double>(start_vec2)) / CLOCKS_PER_SEC;
	// std::cout << "sort time not jacob: " << time_vec2 << std::endl;

	// for (size_t i = 0; i < sorted_vec1.size(); ++i) {
	// 	std::cout << sorted_vec1[i] << ", ";
	// }
	// std::cout << std::endl;
	return 0;
}

// int	main(int argc, char **argv) {
// 	if (argc != 2 || !PmergeMe::checkValidArgs(argv[1])) {
// 		std::cerr << "Error" << std::endl;
// 		return (1);
// 	}
// 	PmergeMe arr;
// 	arr.setVectorAndList(argv[1]);
// 	arr.sortMergeInsertion();
// 	return (0);
// }
