#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie
{
	public:
		Zombie();
		explicit Zombie(const std::string& name);
		~Zombie();
		void	announce(void);
		void	setName(const std::string& name);
	private:
		std::string	_name;
};

Zombie*    zombieHorde(const int& N, const std::string& name );

#endif