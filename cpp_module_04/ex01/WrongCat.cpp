#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	this->type = "Wrong Cat";
	std::cout << "WrongCat Default Constructor Called" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat Destructor Called" << std::endl;
}

void	WrongCat::makeSound(void) const
{
	std::cout << "WrongCat Class makeSound" << std::endl;
	std::cout << "nya nya nya nya" << std::endl;
}
