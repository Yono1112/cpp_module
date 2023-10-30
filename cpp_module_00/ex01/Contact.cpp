#include "Contact.hpp"
#include <iostream>
#include <string>
#include <cstdlib>

// void	Contact::setNum(int new_num)
// {
// 	std::cout << "start setNum" << std::endl;
// 	num = new_num;
// }
// 
// int	Contact::getNum(void)
// {
// 	std::cout << "start getNum" << std::endl;
// 	return (num);
// }

void	Contact::setContact(void)
{
	std::string	new_str[5];

	std::cout << "start setContact" << std::endl;
	// std::cout << "Enter Num: ";
	// std::getline(std::cin, new_str[0]);
	// num = stoi(new_str);
	std::cout << "Enter First Name: ";
	std::getline(std::cin, new_str[0]);
	first_name = new_str[0];
	// std::cout << "Enter Last Name: ";
	// std::getline(std::cin, new_str[1]);
	// last_name = new_str;
	// std::cout << "Enter Nick Name: ";
	// std::getline(std::cin, new_str[2]);
	// nick_name = new_str;
	// std::cout << "Enter Phone Name: ";
	// std::getline(std::cin, new_str[3]);
	// nick_name = new_str;
}

std::string	Contact::getFirstName(void)
{
	std::cout << "start getContact" << std::endl;
	return (first_name);
}

void	Contact::printContact(void)
{
	std::cout << "start printCotact" << std::endl;
	// std::cout << "num: " << num << std::endl;
	std::cout << "first_name: " << first_name << std::endl;
}
