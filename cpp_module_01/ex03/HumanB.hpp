#ifndef HUMANB_HPP
# define HUMANB_HPP

#include <string>
#include <iostream>
#include "Weapon.hpp"

class HumanB
{
	public:
		~HumanB();
		explicit HumanB(const std::string name);
		void	attack();
		void	setWeapon(Weapon& weapon);
	private:
		std::string	_name;
		Weapon*		_weapon;
};

#endif