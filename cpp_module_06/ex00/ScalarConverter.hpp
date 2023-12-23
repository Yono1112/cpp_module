#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <sstream>
#include <cstring>

#define CHAR_LITERAL 0
#define INT_LITERAL 1
#define FLOAT_LITERAL 2
#define DOUBLE_LITERAL 3
#define PSEUDO_LITERAL 4

class ScalarConverter {
	public:
		static void	convert(const std::string& str);
		class LiteralException: public std::exception {
			public:
				LiteralException(const std::string& e): _error_message(e) {};
				virtual const char* what(void) const throw();
				~LiteralException() throw() {};
			private:
				std::string	_error_message;
		};
	private:
		ScalarConverter();
		~ScalarConverter();
		static void	printCharLiteral(const std::string& str);
		static void	printPreudoLiteral(const std::string& str);
		static int	detectLiteral(const std::string& str);
		static bool	checkCharLiteral(const std::string& str);
		static bool	checkIntLiteral(const std::string& str);
		static bool	checkPreudoLiteral(const std::string& str);
		static bool	checkDoubleLiteral(const std::string& str);
		static bool	checkFloatLiteral(std::string str);
};

#endif
