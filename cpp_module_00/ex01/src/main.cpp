#include <iostream>
#include <string>
#include <cstdlib>
#include "PhoneBook.hpp"
#include "Contact.hpp"

void	check_command(std::string str, PhoneBook  *phone_book)
{
	if (str == "EXIT")
	{
		std::cout << "You Enter EXIT COMMAND" << std::endl;
		exit(EXIT_SUCCESS);
	}
	else if (str == "SEARCH")
	{
		std::cout << "You Enter SEARCH COMMAND" << std::endl;
		phone_book->search();
	}
	else if (str == "ADD")
	{
		std::cout << "You Enter ADD COMMAND" << std::endl;
		phone_book->add();
	}
	else
		std::cout << "You Don't Enter Any COMMAND" << std::endl;
}

int main(void)
{
	std::string	str;
	PhoneBook	phone_book;

	std::cout << "HELLO MY AWESOME PHONEBOOK!" << std::endl;
	while (1)
	{
		std::cout << "ENTER COMMAND (ADD, SEARCH or EXIT): ";
		if (!std::getline(std::cin, str))
			break ;
		check_command(str, &phone_book);
		if (std::cin.eof())
			break ;
	}
	return (0);
}
