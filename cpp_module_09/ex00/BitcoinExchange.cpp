#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() 
	: _data_map(){
	std::cout << "Default Constructor Called" << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) 
	: _data_map(other._data_map){
	std::cout << "Copy Constructor Called" << std::endl;
}

BitcoinExchange::~BitcoinExchange() {
	std::cout << "Destructor Called" << std::endl;
}

BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange& other) {
	std::cout << "Copy Assignment Operator Called" << std::endl;
	if (this != &other) {
		this->_data_map = other._data_map;
	}
	return (*this);
}

void	BitcoinExchange::printError(std::string error_message) {
	std::cerr << "ERROR: " << error_message << std::endl;
}

bool	BitcoinExchange::canOpenFiles(const char *arg_file) {
	std::ifstream	input_file(arg_file);
	std::ifstream	csv_file("data.csv");

	if (!input_file.is_open()) {
		printError("could not open input file");
		return (false);
	} else if (!csv_file.is_open()) {
		printError("could not open csv file");
		return (false);
	}
	return (true);
}

void	BitcoinExchange::addCSVToBitcoinMap() {
	std::cout << "run addCSVToBitcoinMap" << std::endl;

	std::ifstream	csv_file("data.csv");
	std::string	line;

	while (getline(csv_file, line)) {
		std::cout << line << std::endl;
	}
}
