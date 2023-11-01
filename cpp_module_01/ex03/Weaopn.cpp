#include "Weapon.hpp"

Weapon::Weapon()
	: _type("")
{
}

Weapon::Weapon(std::string type)
	: _type(type)
{
	std::cout << "Constructor: " << _type << std::endl;
}

Weapon::~Weapon()
{
	std::cout << "Destructor" << std::endl;
}

void	Weapon::setType(std::string type)
{
	_type = type;
	std::cout << "setType: " << _type << std::endl;
}

std::string	Weapon::getType(void)
{
	return (_type);
}
