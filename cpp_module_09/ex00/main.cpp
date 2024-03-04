#include "BitcoinExchange.hpp"

int	main(int argc, char **argv) {
	if (argc != 2) {
		BitcoinExchange::printError("could not open the file");
		return (1);
	}
	if (!BitcoinExchange::canOpenFiles(argv[1])) {
		return (1);
	}
	BitcoinExchange	btc;
	try {
		btc.addCSVToMap();
	} catch (const std::exception& e) {
		return (1);
	}
	btc.addInputToDeque(argv[1]);
	btc.outputBitcoinExchange();
	return (0);
}
