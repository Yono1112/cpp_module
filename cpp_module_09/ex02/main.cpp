#include "PmergeMe.hpp"

int	main(int argc, char **argv) {
	if (argc != 2 || !PmergeMe::checkValidArgs(argv[1])) {
		std::cout << argc << std::endl;
		std::cerr << "Error" << std::endl;
		return (1);
	}
	PmergeMe arr;
	arr.setVectorAndList(argv[1]);
	arr.sortMergeInsertion();
	return (0);
}
