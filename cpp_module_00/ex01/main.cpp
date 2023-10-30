#include <iostream>
#include <string>
#include <cstdlib>
#include "PhoneBook.hpp"
#include "Contact.hpp"

void	check_command(std::string str, PhoneBook phone_book, Contact *contact)
{
	if (str == "EXIT")
	{
		std::cout << "You Enter EXIT COMMAND" << std::endl;
		exit(EXIT_SUCCESS);
	}
	else if (str == "SEARCH")
	{
		std::cout << "You Enter SEARCH COMMAND" << std::endl;
		phone_book.search(*contact);
	}
	else if (str == "ADD")
	{
		std::cout << "You Enter ADD COMMAND" << std::endl;
		phone_book.add(contact);
	}
	else
		std::cout << "You Don't Enter Any COMMAND" << std::endl;
}

int main(void)
{
	std::string	str;
	PhoneBook	phone_book;
	Contact		contact;

	// contact.setNum(0);
	// std::cout << contact.getNum() << std::endl;
	std::cout << "HELLO MY AWESOME PHONEBOOK!" << std::endl;
	while (1)
	{
		std::cout << "ENTER COMMAND (ADD, SEARCH or EXIT): ";
		std::getline(std::cin, str);
		check_command(str, phone_book, &contact);
		// std::cout << "getNum:" << contact.getNum() << std::endl;
	}
	return (0);
}
