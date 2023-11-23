#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int	main(void)
{
	Animal* meta = new Animal();
	std::cout << meta->getType() << " " << std::endl;
	meta->makeSound();
	return (0);
}
