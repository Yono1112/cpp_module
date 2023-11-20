#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void)
{
	std::cout << "ScavTrap Default Constructor Called" << std::endl;
}

ScavTrap::ScavTrap(std::string name)
{
	setName(name);
	setHitPoints(_scav_hit_points);
	setEnergyPoints(_scav_energy_points);
	setAttackDamage(_scav_attack_damage);
	std::cout << "ScavTrap Constructor Called" << std::endl;
	std::cout << "name is " << getName() << std::endl;
	std::cout << "_hit_points is " << getHitPoints() << std::endl;
	std::cout << "_energy_points is " << getEnergyPoints() << std::endl;
	std::cout << "_attack_damage is " << getAttackDamage() << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap Destructor Called" << std::endl;
}

void	ScavTrap::guardGate(void)
{
	if (checkPoints())
	{
		std::cout << "ScavTrap " << getName() << " is now in Gate keeper mode" << std::endl;
	}
}

void	ScavTrap::attack(const std::string& target)
{
	std::cout << getName() << " use ATTACK" << std::endl;
	if (checkPoints())
	{
		int num = getEnergyPoints();
		setEnergyPoints(--num);
		std::cout << "ScavTrap " << getName() << " attacks " << target << ", causing " << getAttackDamage() << " points of damage!" << std::endl;
	}
}
