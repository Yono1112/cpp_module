#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <cstring>

#define CHAR_LITERAL 0
#define INT_LITERAL 1
#define FLOAT_LITERAL 2
#define DOUBLE_LITERAL 3
#define PSEUDO_LITERAL 4

class ScalarConverter {
	public:
		static void	convert(const std::string& str);
	private:
		ScalarConverter();
		~ScalarConverter();
		static int	detectLiteral(const std::string& str);
		static bool	checkCharLiteral(const std::string& str);
		// bool	checkDoubleLiteral(const std::string& str);
		// bool	checkFloatLiteral(const std::string& str);
		// bool	checkIntLiteral(const std::string& str);
		// bool	checkPreudoLiteral(const std::string& str);
};

#endif
