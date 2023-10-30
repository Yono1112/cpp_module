#include "Contact.hpp"
#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <cstring>

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
Contact::Contact() 
	: first_name("")
	, last_name("")
	, nick_name("")
	, phone_number("")
	, darkest_secret("") {

	std::cout << "Contact con" << std::endl;
}

Contact::~Contact() {
	std::cout << "Contact des" << std::endl;
}

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

std::string	check_length(std::string str)
{
	if (str.length() > 10)
	{
		while (str.length() > 9)
			str.pop_back();
		str.push_back('.');
	}
	return (str);
}

void	Contact::printContactAll(int index)
{
	std::cout << std::setw(10);
	std::cout << "Index";
	std::cout << "|" << std::setw(10);
	std::cout << index << std::endl;
	std::cout << std::setw(10);
	std::cout << "FirstName";
	std::cout << "|" << std::setw(10);
	std::cout << first_name << std::endl;
	std::cout << std::setw(10);
	std::cout << "LastName";
	std::cout << "|" << std::setw(10);
	std::cout << last_name << std::endl;
	std::cout << std::setw(10);
	std::cout << "NickName";
	std::cout << "|" << std::setw(10);
	std::cout << nick_name << std::endl;
	std::cout << std::setw(10);
	std::cout << "PhoneNum";
	std::cout << "|" << std::setw(10);
	std::cout << phone_number << std::endl;
	std::cout << std::setw(10);
	std::cout << "Secret";
	std::cout << "|" << std::setw(10);
	std::cout << darkest_secret << std::endl;
}

void	Contact::printContactOnlyName(int index)
{
	// std::cout << "start printCotact" << std::endl;
	std::cout << "|" << std::setw(10);
	std::cout << index;
	std::cout << "|" << std::setw(10);
	std::cout << check_length(first_name);
	std::cout << "|" << std::setw(10);
	std::cout << check_length(last_name);
	std::cout << "|" << std::setw(10);
	std::cout << check_length(nick_name) << "|";
	std::cout << std::endl;
} 
