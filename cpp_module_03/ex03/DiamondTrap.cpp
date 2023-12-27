#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name)
	: ClapTrap(name, 100, 20, 30)
{
	setNameDiamond(name);
	setName(name.append("_clap_name"));
	// setHitPoints(_frag_hit_points);
	// setEnergyPoints(_scav_energy_points);
	// setAttackDamage(_frag_attack_damage);
	std::cout << "Diamond Constructor Called" << std::endl;
	std::cout << "name is " << getNameDiamond() << std::endl;
	std::cout << "ClapTrap name is " << getName() << std::endl;
	std::cout << "_hit_points is " << getHitPoints() << std::endl;
	std::cout << "_energy_points is " << getEnergyPoints() << std::endl;
	std::cout << "_attack_damage is " << getAttackDamage() << std::endl;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap Destructor Called" << std::endl;
}

void	DiamondTrap::setNameDiamond(std::string name)
{
	_name = name;
}

std::string	DiamondTrap::getNameDiamond(void)
{
	return (_name);
}

void	DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << "DiamondTrap name is " << getNameDiamond() << std::endl;
	std::cout << "ClapTrap name is " << getName() << std::endl;
}
