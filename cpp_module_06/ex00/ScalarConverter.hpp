#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <cstring>

class ScalarConverter {
	public:
		static void	convert(const std::string& str);
	private:
		ScalarConverter();
		~ScalarConverter();
		int	classifyLiteral(const std::string& str);
};

#endif
