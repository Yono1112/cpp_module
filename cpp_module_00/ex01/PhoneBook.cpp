#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>

void	PhoneBook::search(Contact contact)
{
	std::cout << "start search" << std::endl;
	std::cout << contact.getNum() << std::endl;
}

void	PhoneBook::add(Contact *contact)
{
	std::string	new_str;
	int		new_num;

	std::cout << "start add" << std::endl;
	std::cout << "Enter Num: ";
	// std::cin >> new_num;
	std::getline(std::cin, new_str);
	new_num = stoi(new_str);
	contact->setNum(new_num);
	std::cout << contact->getNum() << std::endl;
}
