#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name)
	: _name(name),
	_hit_points(10),
	_energy_points(10),
	_attack_damage(10)
{
	std::cout << "Constructor Called" << std::endl;
	std::cout << "name is " << _name << std::endl;
	(void)_hit_points;
	(void)_energy_points;
	(void)_attack_damage;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor Called" << std::endl;
}
