#include "Zombie.hpp"

Zombie::Zombie()
{
}

Zombie::Zombie(const std::string& name)
	: _name(name)
{
}

Zombie::~Zombie()
{
	std::cout << "destructor: " << _name << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName(const std::string& name)
{
	_name = name;
}