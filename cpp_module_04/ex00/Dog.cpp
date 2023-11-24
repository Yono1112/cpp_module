#include "Dog.hpp"

Dog::Dog()
{
	this->type = "Dog";
	std::cout << "Dog Default Constructor Called" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog Destructor Called" << std::endl;
}

Dog::Dog(const Dog& other)
{
	std::cout << "Dog Copy Constructor Called" << std::endl;
}

Dog&	Dog::operator=(const Dog& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->type = other.type;
	}
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << "Dog Class makeSound" << std::endl;
	std::cout << "wan wan wan wan" << std::endl;
}
