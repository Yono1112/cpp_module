#include "Fixed.hpp"

Fixed::Fixed()
	: _fixed_point_num(0)
{
	std::cout << "Default constructor called" << std::endl;
}

// Fixed::Fixed(const Fixed& fixed)
// {
// 	std::cout << "Copy constructor called" << std::endl;
// }

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (_fixed_point_num);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	_fixed_point_num = raw;
}