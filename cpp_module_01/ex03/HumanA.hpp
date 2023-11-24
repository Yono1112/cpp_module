#ifndef HUMANA_HPP
# define HUMANA_HPP

#include <string>
#include <iostream>
#include "Weapon.hpp"

class HumanA
{
	public:
		~HumanA();
		HumanA(const std::string& name, Weapon& weapon);
		void	attack();
	private:
		std::string	_name;
		Weapon&	_weapon;
};

#endif