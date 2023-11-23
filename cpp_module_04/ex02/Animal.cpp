#include "Animal.hpp"

Animal::Animal()
	: type("")
{
	std::cout << "Animal Default Constructor Called" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal Destructor Called" << std::endl;
}

void	Animal::setType(std::string new_name)
{
	this->type = new_name;
}

std::string	Animal::getType(void) const
{
	return (this->type);
}

// void	Animal::makeSound(void) const
// {
// 	std::cout << "Animal Class makeSound" << std::endl;
// }
