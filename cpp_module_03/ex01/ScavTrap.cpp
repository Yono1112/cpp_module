#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name)
{
	_name = name;
	_hit_points = 50;
	_energy_points = 20;
	_attack_damage = 20;
	std::cout << "ScavTrap Constructor Called" << std::endl;
	std::cout << "name is " << _name << std::endl;
	std::cout << "_hit_points is " << _hit_points << std::endl;
	std::cout << "_energy_points is " << _energy_points << std::endl;
	std::cout << "_attack_damage is " << _attack_damage << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ClapTrap Destructor Called" << std::endl;
}

void	ScavTrap::guardGate(void)
{
	if (checkPoints())
	{
		std::cout << "ClapTrap " << this->_name << " is now in Gate keeper mode" << std::endl;
	}
}
