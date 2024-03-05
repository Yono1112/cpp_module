#include "PmergeMe.hpp"

int main(const int argc, const char **argv) {
	if (argc < 2 || !PmergeMe::checkValidArgs(argc, argv)) {
		std::cerr << "ERROR: invalid argument" << std::endl;
		return (1);
	}
	PmergeMe arr;
	try {
		arr.setVectorAndList(argv[1]);
		arr.sortVectorAndList();
	} catch (const std::exception& e) {
		std::cerr << "ERROR: catch std::exception: " << e.what() << std::endl;
	}
	return (0);
}
