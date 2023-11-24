#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int	main(void)
{
	{
		// const Animal* meta = new Animal();
		const Animal* i = new Cat();
		const Animal* j = new Dog();

		std::cout << i->getType() << " " << std::endl;
		std::cout << j->getType() << " " << std::endl;
		i->makeSound();
		j->makeSound();
		// meta->makeSound();

		// delete meta;
		delete i;
		delete j;

		WrongAnimal* k = new WrongCat();
		std::cout << k->getType() << " " << std::endl;
		k->makeSound();

		delete k;
	}
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
	}
	return (0);
}

// __attribute__((destructor))
// static void	destructor(void)
// {
// 	system("leaks -q animal");
// }
