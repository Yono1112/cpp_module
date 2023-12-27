#ifndef FRAG_TRAP_HPP
# define FRAG_TRAP_HPP

#include "ClapTrap.hpp"

class FragTrap: virtual public ClapTrap
{
	public:
		FragTrap();
		FragTrap(std::string name);
		~FragTrap();
		void	highFivesGuys(void);
	protected:
		// static const int	_frag_hit_points = 100;
		// const int	_frag_energy_points;
		// static const int	_frag_attack_damage = 30;
};

#endif
