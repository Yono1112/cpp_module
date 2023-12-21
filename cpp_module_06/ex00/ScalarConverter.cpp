#include "ScalarConverter.hpp"
// static bool	checkCharLiteral(const std::string& str);

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

int	ScalarConverter::detectLiteral(const std::string& str) {
	if (ScalarConverter::checkCharLiteral(str))
		return (CHAR_LITERAL);
	// else if (checkDoubleLiteral(str))
	// 	return (DOUBLE_LITERAL);
	// else if (checkFloatLiteral(str))
	// 	return (DOUBLE_LITERAL);
	// else if (checkIntLiteral(str))
	// 	return (DOUBLE_LITERAL);
	// else if (checkPreudoLiteral(str))
	// 	return (DOUBLE_LITERAL);
	else
		return (-1);
}
