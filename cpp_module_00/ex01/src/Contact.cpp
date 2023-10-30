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
	: first_name("None")
	, last_name("None")
	, nick_name("None")
	, phone_number("None")
	, darkest_secret("None") {

	std::cout << "Contact con" << std::endl;
}

Contact::~Contact() {
	std::cout << "Contact des" << std::endl;
}

bool	isSpaceOrEmpty(std::string str)
{
	// std::cout << (int)str.length();
	if (str.length() == 0)
		return (true);
	for (int i = 0; i < (int)str.length() ; i++) {
		if (str[i] != ' ' && str[i] != '\t')
			return (false);
	}
	return (true);
}

bool	isOnlyDigit(std::string str)
{
	for (int i = 0; i < (int)str.length() ; i++) {
		if (!std::isdigit(str[i]))
			return (false);
	}
	return (true);
}

std::string	inputMemberString(std::string str_member, bool flag_num)
{
	std::string	new_str;

	while (1)
	{
		std::cout << "Enter " << str_member;
		std::getline(std::cin, new_str);
		if (flag_num && !isOnlyDigit(new_str))
		{
			std::cout << "You Must Enter Only Number" << std::endl;
			continue ;
		}
		if (!isSpaceOrEmpty(new_str))
			break ;
		std::cout << "You Must Enter At Least One Character" << std::endl;
	}
	return (new_str);
}

void	Contact::setContact(void)
{
	std::cout << "start setContact" << std::endl;
	first_name = inputMemberString("First Name: ", false);
	last_name = inputMemberString("Last Name: ", false);
	nick_name = inputMemberString("Nick Name: ", false);
	phone_number = inputMemberString("Phone Number: ", true);
	darkest_secret = inputMemberString("Darkest Secret: ", false);
}

std::string	Contact::getFirstName(void)
{
	std::cout << "start getContact" << std::endl;
	return (first_name);
}

std::string	checkLength(std::string str)
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
	std::cout << checkLength(first_name);
	std::cout << "|" << std::setw(10);
	std::cout << checkLength(last_name);
	std::cout << "|" << std::setw(10);
	std::cout << checkLength(nick_name) << "|";
	std::cout << std::endl;
} 
