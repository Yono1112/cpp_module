#include "Zombie.hpp"

Zombie*    zombieHorde(const int& N, const std::string& name )
{
	Zombie *zombie = new Zombie[N];

	for (int i = 0; i < N; i++)
		zombie[i].setName(name);
	return (zombie);
}