#include "BitcoinExchange.hpp"

int	main() {
	BitcoinExchange	btc1;
	BitcoinExchange	btc2(btc1);
	BitcoinExchange	btc3;

	btc3 = btc1;
	return (0);
}
