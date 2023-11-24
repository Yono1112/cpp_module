#include "FragTrap.hpp"

FragTrap::FragTrap(void)
	// : _frag_energy_points(100)
	// , _frag_attack_damage(30)
{
	std::cout << "FragTrap Default Constructor Called" << std::endl;
}

FragTrap::FragTrap(std::string name)
	: ClapTrap(name, 100, 100, 30)
	// , _frag_energy_points(100)
	// , _frag_attack_damage(30)
{
	std::cout << "FragTrap Constructor Called" << std::endl;
	std::cout << "name is " << getName() << std::endl;
	std::cout << "_hit_points is " << getHitPoints() << std::endl;
	std::cout << "_energy_points is " << getEnergyPoints() << std::endl;
	std::cout << "_attack_damage is " << getAttackDamage() << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap Destructor Called" << std::endl;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << getName() << ", you're amazing! High five for being awesome!" << std::endl;
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
