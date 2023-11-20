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
		int		getAttackDamage(void);
		std::string	getName(void);
	protected:
		bool	checkPoints(void);
		void	setName(std::string name);
		void	setHitPoints(int num);
		void	setEnergyPoints(int num);
		void	setAttackDamage(int num);
		int		getHitPoints(void);
		int		getEnergyPoints(void);
		static const int	_clap_hit_points = 10;
		static const int	_clap_energy_points = 10;
		static const int	_clap_attack_damage = 0;
	private:
		std::string	_name;
		int			_hit_points;
		int			_energy_points;
		int			_attack_damage;
};

#endif
