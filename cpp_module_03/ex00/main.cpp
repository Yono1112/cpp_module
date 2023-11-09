#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	bob("bob");

	// for (int i = 0; i < 11; i++)
	// 	bob.beRepaired(10);
	bob.attack("bob");
	bob.takeDamage(10);
	bob.beRepaired(10);
}
