#include "ScalarConverter.hpp"

void	ScalarConverter::printCharLiteral(const std::string& str) {
	if (!std::isprint(str[0])) {
		std::cout << "char: Non displayable" << std::endl;
	} else {
		std::cout << "char: '" << static_cast<char>(str[0]) << "'" << std::endl;
	}
	std::cout << "int: " << static_cast<int>(str[0]) << std::endl;
	std::cout << "float: " << static_cast<float>(str[0]) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(str[0]) << ".0" << std::endl;
}

void	ScalarConverter::printPreudoLiteral(const std::string& str) {
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	if (str == "-inff" || str == "+inff" || str == "nanf") {
		std::string tmp_str = str;
		std::cout << "float: " << str << std::endl;
		std::cout << "double: " << tmp_str.erase(tmp_str.length() - 1, 1) << std::endl;
	} else {
		std::cout << "float: " << str << "f" << std::endl;
		std::cout << "double: " << str << std::endl;
	}
}

void	ScalarConverter::printIntLiteral(const std::string& str) {
	std::istringstream	iss(str);
	int num;

	iss >> num;
	if (num < 32 || 126 < num) {
		std::cout << "char: Non displayable" << std::endl;
	} else {
		std::cout << "char: '" << static_cast<char>(num) << "'" << std::endl;
	}
	std::cout << "int: " << num << std::endl;
	std::cout << "float: " << static_cast<float>(num) << ".0f" << std::endl;
	std::cout << "float: " << static_cast<double>(num) << ".0" << std::endl;
}

void	ScalarConverter::convert(const std::string& str) {
	std::cout << "str: " << str << std::endl;
	int literal_type = detectLiteral(str);
	switch (literal_type) {
		case CHAR_LITERAL:
			std::cout << "char literal" << std::endl;
			printCharLiteral(str);
			break;
		case INT_LITERAL:
			std::cout << "int literal" << std::endl;
			printIntLiteral(str);
			break;
		case FLOAT_LITERAL:
			std::cout << "float literal" << std::endl;
			break;
		case DOUBLE_LITERAL:
			std::cout << "double literal" << std::endl;
			break;
		case PSEUDO_LITERAL:
			std::cout << "pseudo literal" << std::endl;
			printPreudoLiteral(str);
			break;
		default:
			std::cout << "undefined literal" << std::endl;
	}
}

bool	ScalarConverter::checkCharLiteral(const std::string& str) {
	return (str.length() == 1);
}

bool	ScalarConverter::checkIntLiteral(const std::string& str) {
	for (size_t i = 0; i < str.length(); i++) {
		if (!std::isdigit(str[i]))
			return (false);
	}
	std::istringstream	iss(str);
	std::ostringstream	oss;
	int num;

	iss >> num;
	oss << num;
	if (oss.str() != str)
		throw LiteralException("int overflow");
	return (true);
}

bool	ScalarConverter::checkPreudoLiteral(const std::string& str) {
	return (str == "-inff" || str == "+inff" || str == "nanf" || str == "-inf" || str == "+inf" || str == "nan");
}

bool	ScalarConverter::checkDoubleLiteral(const std::string& str) {
	if (str.find(".") == std::string::npos) {
		return (false);
	}
	double num;
	std::istringstream iss(str);
	iss >> num;

	return (!iss.fail() && iss.eof());
}

bool	ScalarConverter::checkFloatLiteral(std::string str) {
	size_t pos = str.find("f");
	if (pos == std::string::npos) {
		return (false);
	}
	str.erase(pos, 1);
	float num;
	std::istringstream iss(str);
	iss >> num;
	return (!iss.fail() && iss.eof());
}

int	ScalarConverter::detectLiteral(const std::string& str) {
	if (checkPreudoLiteral(str))
		return (PSEUDO_LITERAL);
	else if (checkFloatLiteral(str))
		return (FLOAT_LITERAL);
	else if (checkDoubleLiteral(str))
		return (DOUBLE_LITERAL);
	else if (checkIntLiteral(str))
		return (INT_LITERAL);
	else if (checkCharLiteral(str))
		return (CHAR_LITERAL);
	else
		return (-1);
}

const char*	ScalarConverter::LiteralException::what(void) const throw() {
	return (_error_message.c_str());
}
