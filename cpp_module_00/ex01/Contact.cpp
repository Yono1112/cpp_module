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
	std::cout << "Enter Last Name: ";
	std::getline(std::cin, new_str[1]);
	last_name = new_str[1];
	std::cout << "Enter Nick Name: ";
	std::getline(std::cin, new_str[2]);
	nick_name = new_str[2];
	std::cout << "Enter Phone Name: ";
	std::getline(std::cin, new_str[3]);
	phone_number = new_str[3];
	std::cout << "Enter Darkest Secret: ";
	std::getline(std::cin, new_str[4]);
	darkest_secret = new_str[4];
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
	std::cout << "First Name: " << first_name << std::endl;
	std::cout << "Last Name: " << last_name << std::endl;
	std::cout << "Nick Name: " << nick_name << std::endl;
	std::cout << "Phone Name: " << phone_number << std::endl;
	std::cout << "Darkest Secret: " << darkest_secret << std::endl;
}
