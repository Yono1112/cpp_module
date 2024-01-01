#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <istream>
#include <sstream>
#include <vector>

#define CSV_FILE "data.csv.org"

class BitcoinExchange {
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& other);
		~BitcoinExchange();
		BitcoinExchange& operator=(const BitcoinExchange& other);
		static void	printError(std::string error_message);
		static bool	canOpenFiles(const char *arg_file);
		void	addCSVToBitcoinMap();
		void	addInputToBitcoinMap(const char *file_name);
		void	outputBitcoinExchange();
		bool	checkValidDate(const std::string& date_key);
	private:
		std::map<std::string, double> _data_map;
		std::vector<std::pair<std::string, std::string> > _input_map;
};

#endif
