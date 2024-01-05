#include "RPN.hpp"

int	main(int argc, char **argv) {
	if (argc != 2 || !RPN::checkArguments(argv[1])) {
		std::cerr << "Error" << std::endl;
		return (1);
	}
	// RPN rpn;
	// rpn.setStack(argv[1]);
	return (0);
}
