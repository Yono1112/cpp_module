#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	ClapTrap	bob("bob");
	ScavTrap	jim("jim");

	// for (int i = 0; i < 11; i++)
	// 	bob.beRepaired(10);
	// bob.attack("jim");
	// jim.takeDamage(0);

	jim.attack("bob");
	bob.takeDamage(20);

	jim.guardGate();

	bob.beRepaired(10);
}
