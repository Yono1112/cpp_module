#include <iostream>
#include <string>
#include <cstdlib>
#include "PhoneBook.hpp"
#include "Contact.hpp"

static void	check_command(std::string str, PhoneBook& phone_book)
{
	if (str == "EXIT")
	{
		std::cout << "You Enter EXIT COMMAND" << std::endl;
		exit(EXIT_SUCCESS);
	}
	else if (str == "SEARCH")
		phone_book.search();
	else if (str == "ADD")
		phone_book.add();
	else
		std::cout << "You Don't Enter Any COMMAND" << std::endl;
}

static void	commandInputLoop()
{
	std::string	str;
	PhoneBook	phone_book;

	while (1)
	{
		std::cout << "ENTER COMMAND (ADD, SEARCH or EXIT): ";
		if (!std::getline(std::cin, str))
			return ;
		check_command(str, phone_book);
		if (std::cin.eof())
			return ;
	}
}

int main(void)
{
	std::cout << "HELLO MY AWESOME PHONEBOOK!" << std::endl;
	commandInputLoop();
	return (0);
}
