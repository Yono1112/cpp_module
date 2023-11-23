#include "Dog.hpp"

Dog::Dog()
{
	this->type = "dog";
	this->brain_ptr = new Brain();
	std::cout << "Dog Default Constructor Called" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog Destructor Called" << std::endl;
}

void	Dog::makeSound(void) const
{
	std::cout << "Dog Class makeSound" << std::endl;
	std::cout << "wan wan wan wan" << std::endl;
}
