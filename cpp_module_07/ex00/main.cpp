#include "whatever.hpp"
#include <iostream>
#include <string>

void	testInt() {
	std::cout << "=================================" << std::endl;
	std::cout << "run testInt()" << std::endl;
	int a = 2;
	int b = 3;

	std::cout << "a = " << a << ", b = " << b << std::endl;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
}

void	testDouble () {
	std::cout << "=================================" << std::endl;
	std::cout << "run testDouble()" << std::endl;
	double a = 2.0;
	double b = 3.0;

	std::cout << "a = " << a << ", b = " << b << std::endl;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
}

void	testFloat () {
	std::cout << "=================================" << std::endl;
	std::cout << "run testfloat()" << std::endl;
	float a = 2.0f;
	float b = 3.0f;

	std::cout << "a = " << a << ", b = " << b << std::endl;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
}

void	testString () {
	std::cout << "=================================" << std::endl;
	std::cout << "run testString()" << std::endl;
	std::string a = "aaaa";
	std::string b = "bbbb";

	std::cout << "a = " << a << ", b = " << b << std::endl;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
}

int	main() {
	testInt();
	testDouble();
	testFloat();
	testString();
	return (0);
}
