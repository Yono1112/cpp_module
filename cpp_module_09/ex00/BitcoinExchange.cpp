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
