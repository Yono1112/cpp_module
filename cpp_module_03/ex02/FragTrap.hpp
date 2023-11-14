#ifndef FRAG_TRAP_HPP
# define FRAG_TRAP_HPP

#include "ClapTrap.hpp"

class FragTrap: public ClapTrap
{
	public:
		FragTrap(std::string name);
		~FragTrap();
		void	attack(const std::string& target);
		void	highFivesGuys(void);
	private:
};


#endif