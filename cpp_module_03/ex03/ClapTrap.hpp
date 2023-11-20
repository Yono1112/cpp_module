#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap
{
	public:
		ClapTrap();
		ClapTrap(std::string name);
		~ClapTrap();
		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		bool		checkPoints(void);
	protected:
		void	setName(std::string name);
		void	setHitPoints(int num);
		void	setEnergyPoints(int num);
		void	setAttackDamage(int num);
		std::string	getName(void);
		int		getHitPoints(void);
		int		getEnergyPoints(void);
		int		getAttackDamage(void);
	private:
		std::string	_name;
		int			_hit_points;
		int			_energy_points;
		int			_attack_damage;
};

#endif
