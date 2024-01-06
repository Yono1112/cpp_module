#include "PmergeMe.hpp"

int	main(int argc, char **argv) {
	if (argc != 2 || !PmergeMe::checkValidArgs(argv[1])) {
		std::cerr << "Error" << std::endl;
		return (1);
	}
	PmergeMe lst;
	return (0);
}
