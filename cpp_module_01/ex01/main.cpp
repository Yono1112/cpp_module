#include "Zombie.hpp"

int	main(void)
{
	int	N;

	N = 5;
	Zombie	*zombie = zombieHorde(N, "zombieHorde");
	for (int i = 0; i < N; i++) {
		zombie[i].announce();
	}
	delete[] zombie;
	return (0);
}

// __attribute__((destructor))
// static void	destructor(void)
// {
// 	system("leaks -q zombie");
// }
