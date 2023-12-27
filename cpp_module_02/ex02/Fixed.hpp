#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	public:
		Fixed();
		Fixed(const Fixed& fix);
		Fixed(const int& num);
		Fixed(float num);
		~Fixed();
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		int		toInt(void) const;
		float	toFloat(void) const;
		static Fixed&	min(Fixed& first, Fixed& second);
		static const Fixed&	min(const Fixed& first, const Fixed& second);
		static Fixed&	max(Fixed& first, Fixed& second);
		static const Fixed&	max(const Fixed& first, const Fixed& second);
		Fixed&	operator=(const Fixed& fix);
		bool	operator>(const Fixed& fix) const;
		bool	operator<(const Fixed& fix) const;
		bool	operator>=(const Fixed& fix) const;
		bool	operator<=(const Fixed& fix) const;
		bool	operator==(const Fixed& fix) const;
		bool	operator!=(const Fixed& fix) const;
		Fixed	operator+(const Fixed& fix) const;
		Fixed	operator-(const Fixed& fix) const;
		Fixed	operator*(const Fixed& fix) const;
		Fixed	operator/(const Fixed& fix) const;
		Fixed&	operator++();
		Fixed&	operator--();
		Fixed	operator++(int);
		Fixed	operator--(int);
	private:
		int			_fixed_point_num;
		static const int	_bits = 8;
};

std::ostream&	operator<<(std::ostream& stream, const Fixed& fix);
#endif