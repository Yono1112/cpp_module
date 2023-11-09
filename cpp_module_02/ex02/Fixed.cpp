#include "Fixed.hpp"

Fixed::Fixed()
	: _fixed_point_num(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& fix)
{
	std::cout << "Copy constructor called" << std::endl;
	operator=(fix);
}

Fixed::Fixed(const int& num)
{
	std::cout << "Int constructor called" << std::endl;
	this->_fixed_point_num = num << _bits;
	// std::cout << "_fixed_point_num: " << this->_fixed_point_num << std::endl;
}

Fixed::Fixed(float num)
{
	std::cout << "Float constructor called" << std::endl;
	float	fixed_point_num;
	int		int_num;
	float	fraction_num;

	fixed_point_num = (num * (1 << _bits));
	// std::cout << "fixed_point_num: " << fixed_point_num << std::endl;
	int_num = std::floor(fixed_point_num);
	// std::cout << "int_num: " << int_num << std::endl;
	fraction_num = fixed_point_num - int_num;
	// std::cout << "fraction_num: " << fraction_num << std::endl;
	if (fraction_num > 0.5)
		this->_fixed_point_num = static_cast<int>(fixed_point_num + 1);
	else
		this->_fixed_point_num = static_cast<int>(fixed_point_num);
	// std::cout << "_fixed_point_num: " << this->_fixed_point_num << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int		Fixed::toInt(void) const
{
	return (this->_fixed_point_num >> _bits);
}

float		Fixed::toFloat(void) const
{
	// std::cout << "toFloat: _fixed_point_num: " << this->_fixed_point_num << std::endl;
	return (static_cast<float>(this->_fixed_point_num) / static_cast<float>(1 << _bits));
}

Fixed&	Fixed::operator=(const Fixed& fix)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &fix)
		this->_fixed_point_num = fix.getRawBits();
	return (*this);
}

std::ostream&	operator<<(std::ostream& stream, const Fixed& fix)
{
	stream << fix.toFloat();
	return (stream);
}

int	Fixed::getRawBits(void) const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixed_point_num);
}

void	Fixed::setRawBits(int const raw)
{
	// std::cout << "setRawBits member function called" << std::endl;
	this->_fixed_point_num = raw;
}

bool	Fixed::operator>(const Fixed& fix) const
{
	return (this->_fixed_point_num > fix._fixed_point_num);
}

bool	Fixed::operator<(const Fixed& fix) const
{
	return (this->_fixed_point_num < fix._fixed_point_num);
}

bool	Fixed::operator>=(const Fixed& fix) const
{
	return (this->_fixed_point_num >= fix._fixed_point_num);
}

bool	Fixed::operator<=(const Fixed& fix) const
{
	return (this->_fixed_point_num <= fix._fixed_point_num);
}

bool	Fixed::operator==(const Fixed& fix) const
{
	return (this->_fixed_point_num == fix._fixed_point_num);
}

bool	Fixed::operator!=(const Fixed& fix) const
{
	return (this->_fixed_point_num != fix._fixed_point_num);
}
