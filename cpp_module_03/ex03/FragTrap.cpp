#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name)
{
	_name = name;
	_hit_points = 100;
	_energy_points = 100;
	_attack_damage = 30;
	std::cout << "FragTrap Constructor Called" << std::endl;
	std::cout << "name is " << _name << std::endl;
	std::cout << "_hit_points is " << _hit_points << std::endl;
	std::cout << "_energy_points is " << _energy_points << std::endl;
	std::cout << "_attack_damage is " << _attack_damage << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap Destructor Called" << std::endl;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << _name << ", you're amazing! High five for being awesome!" << std::endl;
}

// void	FragTrap::attack(const std::string& target)
// {
// 	std::cout << this->_name << " use ATTACK" << std::endl;
// 	if (checkPoints())
// 	{
// 		(this->_energy_points)--;
// 		std::cout << "FragTrap " << this->_name << " attacks " << target << ", causing " << this->_attack_damage << " points of damage!" << std::endl;
// 	}
// }
