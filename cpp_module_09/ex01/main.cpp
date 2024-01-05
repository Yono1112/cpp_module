#include "RPN.hpp"

int	main(int argc, char **argv) {
	if (argc != 2 || !RPN::checkArguments(argv[1])) {
		std::cerr << "Error" << std::endl;
		return (1);
	}
	RPN rpn;
	try {
		rpn.calcReversePolish(argv[1]);
	} catch(const std::exception& e) {
		std::cerr << "Error" << std::endl;
		return (1);
	}
	return (0);
}
