#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << "ClapTrap Default Constructor Called" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
	: _name(name),
	_hit_points(_clap_hit_points),
	_energy_points(_clap_energy_points),
	_attack_damage(_clap_attack_damage)
{
	std::cout << "ClapTrap Constructor Called" << std::endl;
	std::cout << "name is " << _name << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap Destructor Called" << std::endl;
}

void	ClapTrap::setName(std::string name)
{
	_name = name;
}

void	ClapTrap::setHitPoints(int num)
{
	_hit_points = num;
}

void	ClapTrap::setEnergyPoints(int num)
{
	_energy_points = num;
}

void	ClapTrap::setAttackDamage(int num)
{
	_attack_damage = num;
}

std::string	ClapTrap::getName(void)
{
	return (_name);
}

int	ClapTrap::getHitPoints(void)
{
	return (_hit_points);
}

int	ClapTrap::getEnergyPoints(void)
{
	return (_energy_points);
}

int	ClapTrap::getAttackDamage(void)
{
	return (_attack_damage);
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
