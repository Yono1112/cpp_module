#ifndef SCAV_TRAP_HPP
# define SCAV_TRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap: virtual public ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(std::string name);
		~ScavTrap();
		void	guardGate(void);
		void	attack(const std::string& target);
	protected:
		static const int	_scav_hit_points = 100;
		static const int	_scav_energy_points = 50;
		static const int	_scav_attack_damage = 20;
	private:
};

#endif
