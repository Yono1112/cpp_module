#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name)
	: _name(name),
	_hit_points(10),
	_energy_points(10),
	_attack_damage(0)
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

// void	attack(const std::string& target)
// {

// }

// void	takeDamage(unsigned int amount)
// {

// }

void	ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << this->_name << " use repair itself" << std::endl;
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
		std::cout << this->_name << " has no energy points left" << std::endl;
		return (false);
	}
	else if (this->_hit_points < 1)
	{
		std::cout << this->_name << " has no hit points left" << std::endl;
		return (false);
	}
	return (true);
}
