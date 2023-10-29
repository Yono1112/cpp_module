#include "Contact.hpp"
#include <iostream>
#include <string>
#include <cstdlib>

void	Contact::setNum(int new_num)
{
	std::cout << "start setNum" << std::endl;
	num = new_num;
}

int	Contact::getNum(void)
{
	std::cout << "start getNum" << std::endl;
	return (num);
}
