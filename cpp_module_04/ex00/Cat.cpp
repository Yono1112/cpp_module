#include "Cat.hpp"

Cat::Cat()
{
	this->type = "cat";
	std::cout << "Cat Default Constructor Called" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat Destructor Called" << std::endl;
}

void	Cat::makeSound(void)
{
	std::cout << "Cat Class makeSound" << std::endl;
	std::cout << "nya nya nya nya" << std::endl;
}
