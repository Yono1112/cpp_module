#include "Zombie.hpp"

int	main(void)
{
	Zombie	*new_zombie1 = newZombie("new1");
	Zombie	*new_zombie2 = newZombie("new2");

	randomChump("random1");
	(*new_zombie1).announce();
	randomChump("random2");
	(*new_zombie2).announce();
	delete(new_zombie1);
	delete(new_zombie2);
	return (0);
}

// __attribute__((destructor))
// static void	destructor(void)
// {
// 	system("leaks -q zombie");
// }
