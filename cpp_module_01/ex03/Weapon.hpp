#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <string>
#include <iostream>

class Weapon
{
	public:
		Weapon();
		~Weapon();
		explicit Weapon(const std::string& type);
		void		setType(const std::string& type);
		std::string	getType() const;
	private:
		std::string	_type;
};

#endif