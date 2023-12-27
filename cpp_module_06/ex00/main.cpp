#include "ScalarConverter.hpp"

int	main(int argc, char **argv) {
	if (argc != 2) {
		std::cout << "ERROR: invalid argument" << std::endl;
		return (1);
	} else {
		try {
			ScalarConverter::convert(argv[1]);
		} catch (const std::exception& e) {
			std::cerr << "Catch std::exception: " << e.what() << std::endl;
			return (1);
		}
	}
	return (0);
}
