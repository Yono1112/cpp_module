#include "Fixed.hpp"

int	main(void)
{
	Fixed	a;
	Fixed	b(10);
	Fixed	c(42.42f);
	Fixed	d(b);

	a = Fixed(1234.4321f);

	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	std::cout << "a > b " << (a > b) << std::endl;
	std::cout << "a < b " <<(a < b) << std::endl;
	std::cout << "a >= b " <<(a >= b) << std::endl;
	std::cout << "a <= b " <<(a <= b) << std::endl;
	std::cout << "a == b " <<(a == b) << std::endl;
	std::cout << "a != b " <<(a != b) << std::endl;
	std::cout << "a + b " <<(a + b) << std::endl;
	std::cout << "a - b " <<(a - b) << std::endl;
	std::cout << "a * b " <<(a * b) << std::endl;
	std::cout << "a / b " <<(a / b) << std::endl;
	std::cout << "++a " << ++a << std::endl;
	std::cout << "--a " << --a << std::endl;
	std::cout << "a is " << a << std::endl;
	std::cout << "a++ " << a++ << std::endl;
	std::cout << "a is " << a << std::endl;
	std::cout << "a-- " << a-- << std::endl;
	std::cout << "a is " << a << std::endl;
	std::cout << "min(a, b)" << std::endl;
	std::cout << Fixed::min(a, b) << " is min" << std::endl;
	std::cout << "max(a, b)" << std::endl;
	std::cout << Fixed::max(a, b) << " is max" << std::endl;
	const Fixed	first(10), second(11);
	std::cout << "const first is " << first << ", second is "<< second << std::endl;
	std::cout << "min(first, second) " << std::endl;
	std::cout << Fixed::min(first, second) << " is min" << std::endl;
	std::cout << "max(first, second) " << std::endl;
	std::cout << Fixed::max(first, second) << " is max" <<  std::endl;
	return (0);
}