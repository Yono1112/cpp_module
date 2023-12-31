#include "BitcoinExchange.hpp"

int	main(int argc, char **argv) {
	if (argc != 2) {
		BitcoinExchange::printError("could not open the file");
		return (1);
	}
	(void)argv;
	return (0);
}
