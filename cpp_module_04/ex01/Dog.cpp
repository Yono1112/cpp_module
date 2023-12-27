#include "Dog.hpp"

Dog::Dog()
{
	this->type = "dog";
	std::cout << "Dog Default Constructor Called" << std::endl;
	this->_brain_ptr = new Brain();
}

Dog::~Dog()
{
	delete this->_brain_ptr;
	std::cout << "Dog Destructor Called" << std::endl;
}

Dog::Dog(const Dog& other)
	: Animal(other)
{
	std::cout << "Dog Copy Constructor Called" << std::endl;
	operator=(other);
}

Dog&	Dog::operator=(const Dog& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->type = other.type;
		if (this->_brain_ptr)
			delete this->_brain_ptr;
		this->_brain_ptr = new Brain(*other._brain_ptr);
	}
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << "Dog Class makeSound" << std::endl;
	std::cout << "wan wan wan wan" << std::endl;
}
