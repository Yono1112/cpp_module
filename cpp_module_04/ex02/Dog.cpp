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

Dog::Dog(const Dog& other)
	: Animal(other)
	, _brain_ptr(other._brain_ptr)
{
	std::cout << "Dog Copy Constructor Called" << std::endl;
}

Dog&	Dog::operator=(const Dog& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->type = other.type;
		this->_brain_ptr = other._brain_ptr;
	}
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << "Dog Class makeSound" << std::endl;
	std::cout << "wan wan wan wan" << std::endl;
}
