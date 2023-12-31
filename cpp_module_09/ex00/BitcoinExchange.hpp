#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <sstream>

class BitcoinExchange {
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& other);
		~BitcoinExchange();
		BitcoinExchange& operator=(const BitcoinExchange& other);
		static void	printError(std::string error_message);
		static bool	canOpenFiles(const char *arg_file);
		void	addCSVToBitcoinMap();
	private:
		std::map<std::string, int> _data_map;
		// std::map<std::string, int> _input_map;
};

#endif
