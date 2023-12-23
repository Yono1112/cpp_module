#include "ScalarConverter.hpp"

void	ScalarConverter::convert(const std::string& str) {
	std::cout << "str: " << str << std::endl;
	int literal_type = detectLiteral(str);
	switch (literal_type) {
		case CHAR_LITERAL:
			std::cout << "char literal" << std::endl;
			break;
		case INT_LITERAL:
			std::cout << "int literal" << std::endl;
			break;
		case FLOAT_LITERAL:
			std::cout << "float literal" << std::endl;
			break;
		case DOUBLE_LITERAL:
			std::cout << "double literal" << std::endl;
			break;
		case PSEUDO_LITERAL:
			std::cout << "pseudo literal" << std::endl;
			break;
		default:
			std::cout << "undefined literal" << std::endl;
	}
}

bool	ScalarConverter::checkCharLiteral(const std::string& str) {
	return (str.length() == 1 && std::isprint(str[0]) && !std::isdigit(str[0]));
}

bool	ScalarConverter::checkIntLiteral(const std::string& str) {
	if (str.find(".") != std::string::npos || str.find("f") != std::string::npos) {
		std::cout << "false" << std::endl;
		return (false);
	}
	for (size_t i = 0; i < str.length(); i++) {
		if (!std::isdigit(str[i]))
			return (false);
	}
	std::istringstream	iss(str);
	std::ostringstream	oss;
	int num;

	iss >> num;
	std::cout << "str: " << str << ", num: " << num << std::endl;
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
	if (ScalarConverter::checkCharLiteral(str))
		return (CHAR_LITERAL);
	else if (checkFloatLiteral(str))
		return (FLOAT_LITERAL);
	else if (checkDoubleLiteral(str))
		return (DOUBLE_LITERAL);
	else if (checkIntLiteral(str))
		return (INT_LITERAL);
	else if (checkPreudoLiteral(str))
		return (PSEUDO_LITERAL);
	else
		return (-1);
}

const char*	ScalarConverter::LiteralException::what(void) const throw() {
	return (_error_message.c_str());
}
