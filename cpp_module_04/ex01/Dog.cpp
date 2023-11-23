#include "Dog.hpp"

Dog::Dog()
{
	this->type = "dog";
	this->_brain_ptr = new Brain();
	std::cout << "Dog Default Constructor Called" << std::endl;
}

Dog::~Dog()
{
	delete this->_brain_ptr;
	std::cout << "Dog Destructor Called" << std::endl;
}

void	Dog::makeSound(void) const
{
	std::cout << "Dog Class makeSound" << std::endl;
	std::cout << "wan wan wan wan" << std::endl;
}
