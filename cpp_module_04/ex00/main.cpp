#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int	main(void)
{
	Animal* meta = new Animal();
	Animal*	i = new Cat();

	std::cout << meta->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	meta->makeSound();
	i->makeSound();
	return (0);
}
