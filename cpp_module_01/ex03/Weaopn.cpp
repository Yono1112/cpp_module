#include "Weapon.hpp"

Weapon::Weapon()
	: _type("")
{
}

Weapon::Weapon(std::string type)
	: _type(type)
{
}

Weapon::~Weapon()
{
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
