#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name)
	: _name(name),
	_hit_points(10),
	_energy_points(10),
	_attack_damage(0)
{
	std::cout << "Constructor Called" << std::endl;
	std::cout << "name is " << _name << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor Called" << std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
	std::cout << this->_name << " use ATTACK" << std::endl;
	if (checkPoints())
	{
		(this->_energy_points)--;
		std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attack_damage << " points of damage!" << std::endl;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	this->_hit_points -= amount;
	if (this->_hit_points < 0)
		this->_hit_points = 0;
	std::cout << "ClapTrap " << this->_name << " takes " << amount << " points of damage! Hit Points are now " << this->_hit_points << " left" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << this->_name << " use REPAIR" << std::endl;
	if (checkPoints())
	{
		(this->_energy_points)--;
		this->_hit_points += amount;
		std::cout << "Repair Success: " << this->_name << " has been repaired for " << this->_hit_points << " hit points, leaving " << this->_energy_points << " energy points" << std::endl;
	}
}

bool	ClapTrap::checkPoints(void)
{
	if (this->_energy_points < 1)
	{
		std::cout << "FAIL: " << this->_name << " has no energy points left" << std::endl;
		return (false);
	}
	else if (this->_hit_points < 1)
	{
		std::cout << "FAIL: " << this->_name << " has no hit points left" << std::endl;
		return (false);
	}
	return (true);
}
