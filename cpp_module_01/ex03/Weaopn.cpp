#include "Weapon.hpp"

Weapon::Weapon()
	: _type("")
{
}

Weapon::Weapon(const std::string& type)
	: _type(type)
{
}

Weapon::~Weapon()
{
}

void	Weapon::setType(const std::string& type)
{
	_type = type;
	std::cout << "setType: " << _type << std::endl;
}

std::string	Weapon::getType(void) const
{
	return (_type);
}
