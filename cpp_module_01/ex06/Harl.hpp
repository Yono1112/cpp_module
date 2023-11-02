#ifndef HARL_HPP
# define HARL_HPP

#include <string>
#include <iostream>


#define DEBUG 0
#define INFO 1
#define WARNING 2
#define ERROR 3
#define UNDEFINE 4
class Harl
{
	public:
		Harl();
		~Harl();
		void	filterLevel(const std::string& level);
	private:
		typedef void	(Harl::*levelPtr)(void);
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);
		void	undefine(void);
};

#endif