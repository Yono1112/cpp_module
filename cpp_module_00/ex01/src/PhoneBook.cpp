#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>

PhoneBook::PhoneBook(void)
	: _index(0)
{
	// std::cout << "PhoneBook con" << std::endl;
}

PhoneBook::~PhoneBook(void)
{
	// std::cout << "PhoneBook des" << std::endl;
}

int	setIndex()
{
	std::string	new_str;
	int		index;

	while (1)
	{
		std::cout << "enter index: ";
		if (!std::getline(std::cin, new_str))
			return (-1);
		if (isOnlyDigit(new_str))
		{
			std::stringstream ss(new_str);
			ss >> index;
			if (0 <= index && index <= 7)
				break ;
			else
			{
				std::cout << "You Must Enter Index From 0 To 7" << std::endl;
				continue ;
			}
		}
		else
		{
			std::cout << "You Must Enter Only Number" << std::endl;
			continue ;
		}
	}
	return (index);
		
}

void	PhoneBook::search(void)
{
	int		index;

	index = 0;
	std::cout << "start search" << std::endl;
	std::cout << "|" << std::setw(10);
	std::cout << "index";
	std::cout << "|" << std::setw(10);
	std::cout << "firstName";
	std::cout << "|" << std::setw(10);
	std::cout << "lastName";
	std::cout << "|" << std::setw(10);
	std::cout << "nickName" << "|" << std::endl;
	for (index = 0; index < 8 ; index++)
		_contacts[index].printContactOnlyName(index);
	index = setIndex();
	if (index < 0)
		return ;
	_contacts[index].printContactAll(index);
}

void	PhoneBook::add(void)
{
	std::cout << "Set Contact In " << _index << " number" << std::endl;
	_contacts[_index++].setContact();
	if (_index == 8)
		_index = 0;
}
