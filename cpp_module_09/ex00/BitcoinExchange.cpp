#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() 
	: _data_map()
	, _input_deq(){
	// std::cout << "Default Constructor Called" << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) 
	: _data_map(other._data_map)
	, _input_deq(other._input_deq){
	// std::cout << "Copy Constructor Called" << std::endl;
}

BitcoinExchange::~BitcoinExchange() {
	// std::cout << "Destructor Called" << std::endl;
}

BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange& other) {
	// std::cout << "Copy Assignment Operator Called" << std::endl;
	if (this != &other) {
		this->_data_map = other._data_map;
		this->_input_deq = other._input_deq;
	}
	return (*this);
}

void	BitcoinExchange::printError(std::string error_message) {
	std::cerr << "ERROR: " << error_message << std::endl;
}

bool	BitcoinExchange::canOpenFiles(const char *arg_file) {
	std::ifstream	input_file(arg_file);
	std::ifstream	csv_file(CSV_FILE);

	if (!input_file.is_open()) {
		printError("could not open input file");
		return (false);
	} else if (!csv_file.is_open()) {
		printError("could not open csv file");
		return (false);
	}
	return (true);
}

void	removeSpaceAndTabStr(std::string& str) {
	str.erase(std::remove(str.begin(), str.end(), ' '), str.end());
	str.erase(std::remove(str.begin(), str.end(), '\t'), str.end());
}

void	BitcoinExchange::addCSVToMap() {
	// std::cout << "run addCSVToBitcoinMap" << std::endl;

	std::ifstream	csv_file(CSV_FILE);
	std::string	line;

	while (getline(csv_file, line)) {
		removeSpaceAndTabStr(line);
		if (line.size() >= 2 && line.substr(0, 2) == "20") {
			std::size_t pos = line.find(',');
			if (pos != std::string::npos) {
				std::string date_str = line.substr(0, pos);
				std::string ex_rate_str = line.substr(pos + 1);
				// std::cout << "before comma: " << date_str << ". after comma: " << ex_rate_str << "." << std::endl;
				std::istringstream iss(ex_rate_str);
				double ex_rate;
				if (iss >> ex_rate && !_data_map[date_str]) {
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

void	BitcoinExchange::addInputToVector(const char *file_name) {
	// std::cout << "run addInputToBitcoinMap" << std::endl;

	std::ifstream	input_file(file_name);
	std::string	line;

	while (getline(input_file, line)) {
		removeSpaceAndTabStr(line);
		if (line.size() >= 2 && line.substr(0, 2) == "20") {
			std::string date_str, ex_rate_str;
			std::size_t pos = line.find('|');
			if (pos != std::string::npos) {
				date_str = line.substr(0, pos);
				ex_rate_str = line.substr(pos + 1);
			} else {
				date_str = line;
				ex_rate_str = "";
			}
			_input_deq.push_back(std::make_pair(date_str, ex_rate_str));
		}
	}
	// for (std::size_t i = 0; i < _input_deq.size(); i++) {
	// 	std::cout << "key: " << _input_deq[i].first << ", value: " << _input_deq[i].second << std::endl;
	// }
	input_file.close();
}

bool	BitcoinExchange::checkValidDate(const std::string& date_key) {
	// std::cout << "date_key: " << date_key << std::endl;
	if (date_key.size() != 10 || date_key.substr(0, 2) != "20") {
		return (false);
	} else if (date_key[4] != '-' || date_key[7] != '-') {
		return (false);
	}
	for (std::size_t i = 0; i < date_key.size(); i++) {
		if ((i != 4 && i != 7) && !std::isdigit(date_key[i])) {
			return (false);
		}
	}
	int month, day;
	std::stringstream(date_key.substr(5, 2)) >> month;
	std::stringstream(date_key.substr(8, 2)) >> day;
	if (month < 1 || 12 < month) {
		return (false);
	} else if (day < 1 || 31 < day) {
		return (false);
	} else if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) {
		return (false);
	} else if (month == 2 && day > 29) {
		return (false);
	}
	return (true);
}

bool	BitcoinExchange::checkValidExRate(const std::string& value, double& ex_num) {
	std::stringstream ss(value);
	ss >> ex_num;
	if (ss.fail()) {
		printError("bad input => " + value);
		return (false);
	} else if (ex_num < 0) {
		printError("not a positive number.");
		return (false);
	} else if (ex_num > 100) {
		printError("too large a number.");
		return (false);
	}
	return (true);
}

std::map<std::string, double>::iterator	BitcoinExchange::findClosestDate(const std::string& key) {
	std::map<std::string, double>::iterator it = _data_map.begin();
	for (; it != _data_map.end(); ++it) {
		if (it->first == key) {
			return (it);
		} else if (it->first > key) {
			break ;
		}
	}
	if (it == _data_map.begin() && it->first != key) {
		throw std::out_of_range("cannot find the closest past date");
	}
	return (--it);
}

void	BitcoinExchange::processInputEntry(const std::string& key, const std::string& value) {
	if (!checkValidDate(key)) {
		printError("bad input => " + key);
		return ;
	}
	double ex_num;
	if (!checkValidExRate(value, ex_num)) {
		return ;
	}
	std::map<std::string, double>::iterator it;
	try {
		it = findClosestDate(key);
		if (it != _data_map.end()) {
			std::cout << key << " => " << value << " = " << ex_num * it->second << std::endl;
		}
	} catch (const std::exception& e) {
		printError("bad input => " + key);
	}
}

void	BitcoinExchange::outputBitcoinExchange() {
	// std::cout << std::endl << "run outputBitcoinExchange" << std::endl;

	// for (std::size_t i = 0; i < _input_deq.size(); i++) {
	// 	std::cout << "key: " << _input_deq[i].first << ", value: " << _input_deq[i].second << std::endl;
	// }
	for (std::size_t i = 0; i < _input_deq.size(); i++) {
		processInputEntry(_input_deq[i].first, _input_deq[i].second);
	}
}
