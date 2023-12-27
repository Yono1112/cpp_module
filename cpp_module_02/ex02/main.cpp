#include "Fixed.hpp"

void	print_subject(void)
{
	Fixed			a;
	Fixed const 	b(Fixed(5.05f) * Fixed(2));

	std::cout << "run print_subject()" << std::endl;
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max(a, b) << std::endl;
	std::cout << "===========================================" << std::endl;
}

void	print_comparison(void)
{
	Fixed	a(42.42f);
	Fixed	b(-42.42f);

	std::cout << "run print_comparison()" << std::endl;
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "a > b " << ((a > b) ? "true" : "false") << std::endl;
	std::cout << "a < b " << ((a < b) ? "true" : "false") << std::endl;
	std::cout << "a >= b " << ((a >= b) ? "true" : "false") << std::endl;
	std::cout << "a <= b " << ((a <= b) ? "true" : "false") << std::endl;
	std::cout << "a == b " << ((a == b) ? "true" : "false")<< std::endl;
	std::cout << "a != b " << ((a != b) ? "true" : "false") << std::endl;
	std::cout << "===========================================" << std::endl;
}

void	print_arithmetic(void)
{
	Fixed	a(42.42f);
	Fixed	b(10);

	std::cout << "run print_arithmetic()" << std::endl;
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "a + b " << (a + b) << std::endl;
	std::cout << "a - b " << (a - b) << std::endl;
	std::cout << "a * b " << (a * b) << std::endl;
	std::cout << "a / b " << (a / b) << std::endl;
	std::cout << "===========================================" << std::endl;
}

void	print_increment_decrement(void)
{
	Fixed	a(42.42f);

	std::cout << "run print_increment_decrement()" << std::endl;
	std::cout << "a is " << a << std::endl;
	std::cout << "++a " << ++a << std::endl;
	std::cout << "a is " << a << std::endl;
	std::cout << "--a " << --a << std::endl;
	std::cout << "a is " << a << std::endl;
	std::cout << "a++ " << a++ << std::endl;
	std::cout << "a is " << a << std::endl;
	std::cout << "a-- " << a-- << std::endl;
	std::cout << "a is " << a << std::endl;
	std::cout << "++(++a) is " << ++(++a) << std::endl;
	std::cout << "a is " << a << std::endl;
	std::cout << "--(--a) is " << --(--a) << std::endl;
	std::cout << "a is " << a << std::endl;
	std::cout << "===========================================" << std::endl;
}

void	print_min_max(void)
{
	Fixed		a(42.42f);
	Fixed		b(10);
	Fixed const	first(10);
	Fixed const	second(-10);

	std::cout << "run print_min_max()" << std::endl;
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "min(a, b)" << std::endl;
	std::cout << Fixed::min(a, b) << " is min" << std::endl;
	std::cout << "max(a, b)" << std::endl;
	std::cout << Fixed::max(a, b) << " is max" << std::endl;
	std::cout << "const first is " << first << ", const second is "<< second << std::endl;
	std::cout << "min(first, second) " << std::endl;
	std::cout << Fixed::min(first, second) << " is min" << std::endl;
	std::cout << "max(first, second) " << std::endl;
	std::cout << Fixed::max(first, second) << " is max" <<  std::endl;
	std::cout << "min(a, second) " << std::endl;
	std::cout << Fixed::min(a, second) << " is min" << std::endl;
	std::cout << "max(first, b) " << std::endl;
	std::cout << Fixed::max(first, b) << " is max" <<  std::endl;
	std::cout << "===========================================" << std::endl;
}

int	main(void)
{
	print_subject();
	print_comparison();
	print_arithmetic();
	print_increment_decrement();
	print_min_max();
	return (0);
}