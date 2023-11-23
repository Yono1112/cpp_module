#include "Cat.hpp"

Cat::Cat()
{
	this->type = "cat";
	this->brain_ptr = new Brain();
	std::cout << "Cat Default Constructor Called" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat Destructor Called" << std::endl;
}

void	Cat::makeSound(void) const
{
	std::cout << "Cat Class makeSound" << std::endl;
	std::cout << "nya nya nya nya" << std::endl;
}
