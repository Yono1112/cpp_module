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

Cat::Cat(const Cat& other)
	: Animal(other)
	, _brain_ptr(other._brain_ptr)
{
	std::cout << "Cat Copy Constructor Called" << std::endl;
}

Cat&	Cat::operator=(const Cat& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->type = other.type;
		this->_brain_ptr = other._brain_ptr;
	}
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << "Cat Class makeSound" << std::endl;
	std::cout << "nya nya nya nya" << std::endl;
}
