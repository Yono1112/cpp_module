#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>

PhoneBook::PhoneBook(void)
	: index(0)
{
	std::cout << "PhoneBook con" << std::endl;
}

PhoneBook::~PhoneBook(void)
{
	std::cout << "PhoneBook des" << std::endl;
}

void	PhoneBook::search(void)
{
	int		index;
	std::string	new_str;

	index = 0;
	std::cout << "start search" << std::endl;
	// contact.printContact();
	for (index = 0; index < 8 ; index++)
		contacts[index].printContact(index, false);
	std::cout << "enter index: ";
	std::getline(std::cin, new_str);
	index = stoi(new_str);
	std:: cout << index << std::endl;
	contacts[index].printContact(index, true);
	// std::cout << "first_name: " << contacts[0].printContact() << std::endl;
	// contacts[0].printContact();
	// std::cout << contact.getNum() << std::endl;
	// std::cout << contact.getFirstName() << std::endl;
}

void	PhoneBook::add(void)
{
	// contacts[0].printContact();
	std::cout << "Sec Contact In " << index << " number" << std::endl;
	contacts[index++].setContact();
	if (index == 8)
		index = 0;
	// contacts[0].printContact();
	// std::cout << "start add" << std::endl;
	// contact->setContact();
	// contacts[0].setContact();
	// std::cout << contact->getNum() << std::endl;
	// std::cout << contact->getFirstName() << std::endl;
}
