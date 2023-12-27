#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap: public ScavTrap, public FragTrap
{
	public:
		DiamondTrap(std::string name);
		~DiamondTrap();
		void	setNameDiamond(std::string name);
		std::string	getNameDiamond(void);
		void	attack(const std::string& target);
		void	whoAmI(void);
	private:
		std::string	_name;
};

#endif