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
		Fixed(const float& num);
		~Fixed();
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		Fixed&	operator=(const Fixed& fix);
		int		toInt(void) const;
		float	toFloat(void) const;
	private:
		int			_fixed_point_num;
		static const int	_bits = 8;
};

std::ostream&	operator<<(std::ostream& stream, const Fixed& fix);
#endif