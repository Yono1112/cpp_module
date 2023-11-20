#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int	main(void)
{
	ClapTrap	bob("bob");
	ScavTrap	jim("jim");
	// FragTrap	michael("michael");
	DiamondTrap	jack("jack");

	// for (int i = 0; i < 11; i++)
	// 	bob.beRepaired(10);
	bob.attack(jim.getName());
	jim.takeDamage(bob.getAttackDamage());

	// jim.attack("bob");
	// bob.takeDamage(20);

	// jim.guardGate();

	// bob.beRepaired(10);

	// michael.highFivesGuys();

	// michael.attack("jim");
	// jim.takeDamage(30);
	jack.whoAmI();

	jack.attack(bob.getName());
	bob.takeDamage(jack.getAttackDamage());
	// bob.beRepaired(20);
}
