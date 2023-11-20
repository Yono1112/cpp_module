#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void)
{
	ClapTrap	bob("bob");
	ScavTrap	jim("jim");
	FragTrap	michael("michael");

	// for (int i = 0; i < 11; i++)
	// 	bob.beRepaired(10);
	// bob.attack("jim");
	// jim.takeDamage(0);

	jim.attack("bob");
	bob.takeDamage(20);

	jim.guardGate();

	// bob.beRepaired(10);

	michael.highFivesGuys();

	michael.attack("jim");
	jim.takeDamage(30);
}
