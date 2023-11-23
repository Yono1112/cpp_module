#include "Cat.hpp"

Cat::Cat()
{
	this->type = "cat";
	this->_brain_ptr = new Brain();
	std::cout << "Cat Default Constructor Called" << std::endl;
}

Cat::~Cat()
{
	delete this->_brain_ptr;
	std::cout << "Cat Destructor Called" << std::endl;
}

void	Cat::makeSound(void) const
{
	std::cout << "Cat Class makeSound" << std::endl;
	std::cout << "nya nya nya nya" << std::endl;
}
