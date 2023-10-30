#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>

void	PhoneBook::search(Contact contact)
{
	std::cout << "start search" << std::endl;
	contact.printContact();
	// std::cout << contact.getNum() << std::endl;
	// std::cout << contact.getFirstName() << std::endl;
}

void	PhoneBook::add(Contact *contact)
{
	std::cout << "start add" << std::endl;
	contact->setContact();
	// std::cout << contact->getNum() << std::endl;
	// std::cout << contact->getFirstName() << std::endl;
}
