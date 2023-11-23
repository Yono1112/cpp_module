#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int	main(void)
{
	int		array_lenghts = 10;
	Animal*	animals[array_lenghts];

	std::cout << "new animals" << std::endl;
	for (int i = 0; i < array_lenghts; i++)
	{
		std::cout << "====================================" << std::endl;
		std::cout << "animals[ " << i << " ]" << std::endl;
		if (i % 2 == 0)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}

	std::cout << std::endl << "delete animals" << std::endl;
	for (int i = 0; i < array_lenghts; i++)
	{
		std::cout << "====================================" << std::endl;
		std::cout << "animals[ " << i << " ]" << std::endl;
		delete animals[i];
	}
	return (0);
}
