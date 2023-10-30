#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>

void	PhoneBook::search(void)
{
	std::cout << "start search" << std::endl;
	// contact.printContact();
	// for (int i = 0; i < 8 ; i++)
	// 	contacts[i].printContact();
	// std::cout << "first_name: " << contacts[0].printContact() << std::endl;
	contacts[0].printContact();
	// std::cout << contact.getNum() << std::endl;
	// std::cout << contact.getFirstName() << std::endl;
}

void	PhoneBook::add(void)
{
	// contacts[0].printContact();
	contacts[0].setContact();
	// contacts[0].printContact();
	// std::cout << "start add" << std::endl;
	// contact->setContact();
	// contacts[0].setContact();
	// std::cout << contact->getNum() << std::endl;
	// std::cout << contact->getFirstName() << std::endl;
}
