#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
	: type("")
{
	std::cout << "WrongAnimal Default Constructor Called" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal Destructor Called" << std::endl;
}

void	WrongAnimal::setType(std::string new_name)
{
	this->type = new_name;
}

std::string	WrongAnimal::getType(void) const
{
	return (this->type);
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << "WrongAnimal Class makeSound" << std::endl;
}
