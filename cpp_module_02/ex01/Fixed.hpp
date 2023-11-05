#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
	public:
		Fixed();
		Fixed(const Fixed& fixed);
		~Fixed();
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		Fixed&	operator=(const Fixed& fix);
	private:
		int			_fixed_point_num;
		static const int	_bits = 8;
};

#endif