#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() 
	: _data_map()
	, _input_map(){
	std::cout << "Default Constructor Called" << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) 
	: _data_map(other._data_map)
	, _input_map(other._input_map){
	std::cout << "Copy Constructor Called" << std::endl;
}

BitcoinExchange::~BitcoinExchange() {
	std::cout << "Destructor Called" << std::endl;
}

BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange& other) {
	std::cout << "Copy Assignment Operator Called" << std::endl;
	if (this != &other) {
		this->_data_map = other._data_map;
		this->_input_map = other._input_map;
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

	std::ifstream	csv_file("data.csv.org");
	std::string	line;

	while (getline(csv_file, line)) {
		if (line.size() >= 2 && line.substr(0, 2) == "20") {
			std::size_t pos = line.find(',');
			if (pos != std::string::npos) {
				std::string date_str = line.substr(0, pos);
				std::string ex_rate_str = line.substr(pos + 1);
				std::cout << "before comma: " << date_str << ". after comma: " << ex_rate_str << std::endl;
				std::istringstream iss(ex_rate_str);
				double ex_rate;
				if (iss >> ex_rate) {
					_data_map[date_str] = ex_rate;
				}
			}
		}
	}
	// for (std::map<std::string, double>::iterator it = _data_map.begin(); it != _data_map.end(); ++it) {
	// 	std::cout << "key: " << it->first << ", value: " << it->second << std::endl;
	// }
	csv_file.close();
}

void	BitcoinExchange::addInputToBitcoinMap(const char *file_name) {
	std::cout << "run addInputToBitcoinMap" << std::endl;

	std::ifstream	input_file(file_name);
	std::string	line;

	while (getline(input_file, line)) {
		if (line.size() >= 2 && line.substr(0, 2) == "20") {
			std::size_t pos = line.find('|');
			if (pos != std::string::npos) {
				std::string date_str = line.substr(0, pos);
				date_str.erase(std::remove(date_str.begin(), date_str.end(), ' '), date_str.end());
				date_str.erase(std::remove(date_str.begin(), date_str.end(), '\t'), date_str.end());
				std::string ex_rate_str = line.substr(pos + 1);
				ex_rate_str.erase(std::remove(ex_rate_str.begin(), ex_rate_str.end(), ' '), ex_rate_str.end());
				ex_rate_str.erase(std::remove(ex_rate_str.begin(), ex_rate_str.end(), '\t'), ex_rate_str.end());
				std::cout << "before comma: " << date_str << ". after comma: " << ex_rate_str << std::endl;
				_input_map.push_back(std::make_pair(date_str, ex_rate_str));
			} else {
				std::cout << "could not find '|'" << std::endl;
				line.erase(std::remove(line.begin(), line.end(), ' '), line.end());
				line.erase(std::remove(line.begin(), line.end(), '\t'), line.end());
				_input_map.push_back(std::make_pair(line, ""));
			}
		}
	}
	for (std::size_t i = 0; i < _input_map.size(); i++) {
		std::cout << "key: " << _input_map[i].first << ", value: " << _input_map[i].second << std::endl;
	}
	input_file.close();
}

void	BitcoinExchange::outputBitcoinExchange() {
	std::cout << std::endl << "run outputBitcoinExchange" << std::endl;

	std::cout << std::endl;
	for (std::size_t i = 0; i < _input_map.size(); i++) {
		std::cout << "key: " << _input_map[i].first << ", value: " << _input_map[i].second << std::endl;
	}
	for (std::size_t i = 0; i < _input_map.size(); i++) {
		std::string key_input_map = _input_map[i].first;
		if (_data_map.find(key_input_map) != _data_map.end()) {
			// std::cout << "can find date: " << key_input_map  << std::endl;
			std::stringstream	iss(_input_map[i].second);
			long	num;

			iss >> num;
			if (num < 0) {
				printError("not a positive number.");
			} else if (num > 100) {
				printError("too large a number.");
			} else {
				std::cout << key_input_map << " => " << _input_map[i].second << " = " << num * _data_map[key_input_map] << std::endl;
			}
		} else {
			std::map<std::string, double>::iterator it = _data_map.begin();
			for (; it != _data_map.end(); ++it) {
				if (it->first > key_input_map) {
					break ;
				}
			}
			if (it != _data_map.begin()) {
				--it;
				// std::cout << "can find the closest past date: " << it->first  << std::endl;
				std::stringstream	iss(_input_map[i].second);
				double	num;

				iss >> num;
				if (num < 0) {
					printError("not a positive number.");
				} else if (num > 100) {
					printError("too large a number.");
				} else {
					std::cout << key_input_map << " => " << _input_map[i].second << " = " << num * it->second << std::endl;
				}
			} else {
				printError("bad input => " + key_input_map);
			}
		}
	}
}
