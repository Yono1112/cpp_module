#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << "ClapTrap Default Constructor Called" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
	: _name(name),
	_hit_points(10),
	_energy_points(10),
	_attack_damage(0)
{
	std::cout << "ClapTrap only name Constructor Called" << std::endl;
	std::cout << "name is " << _name << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap Destructor Called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
	: _name(other._name)
	, _hit_points(other._hit_points)
	, _energy_points(other._energy_points)
	, _attack_damage(other._attack_damage)
{
	std::cout << "Copy Constructor Called" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name, const int& hit_points, const int& energy_points, const int& attack_damage)
	: _name(name)
	, _hit_points(hit_points)
	, _energy_points(energy_points)
	, _attack_damage(attack_damage)
{
	std::cout << "ClapTrap all member value Constructor Called" << std::endl;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_name = other._name;
		this->_hit_points = other._hit_points;
		this->_energy_points = other._energy_points;
		this->_attack_damage = other._attack_damage;
	}
	return (*this);
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
