#include "Zombie.hpp"

void randomChump( std::string name)
{
	Zombie	zombie(name);
	// Zombie	zombie = Zombie(name);

	zombie.announce();
}
