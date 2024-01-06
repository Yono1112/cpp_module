#include "PmergeMe.hpp"

int	main(int argc, char **argv) {
	if (argc != 2 || !PmergeMe::checkValidArgs(argv[1])) {
		std::cerr << "Error" << std::endl;
		return (1);
	}
	PmergeMe arr;
	arr.setVectorAndList(argv[1]);
	std::clock_t start = std::clock();
	arr.sortMergeInsertion();
	std::clock_t end = std::clock();
	double time = 1000000.0 * (static_cast<double>(end) - static_cast<double>(start)) / CLOCKS_PER_SEC;
	std::cout << "time: " << time << " us." << std::endl;
	return (0);
}
