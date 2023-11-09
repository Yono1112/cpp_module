#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	public:
		Fixed();
		Fixed(const Fixed& fixed);
		Fixed(const int& num);
		Fixed(float num);
		~Fixed();
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		int		toInt(void) const;
		float	toFloat(void) const;
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
	private:
		int			_fixed_point_num;
		static const int	_bits = 8;
};

std::ostream&	operator<<(std::ostream& stream, const Fixed& fix);
#endif