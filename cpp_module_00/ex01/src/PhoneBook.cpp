#include "PhoneBook.hpp"
static int	setIndex();
static void	printPrefixFieldName(const std::string& name);


PhoneBook::PhoneBook(void)
	: _index(0)
{
	// std::cout << "PhoneBook con" << std::endl;
}

PhoneBook::~PhoneBook(void)
{
	// std::cout << "PhoneBook des" << std::endl;
}

void	PhoneBook::search(void)
{
	int		index;

	index = 0;
	printPrefixFieldName("index");
	printPrefixFieldName("firstName");
	printPrefixFieldName("lastName");
	printPrefixFieldName("nickName");
	std::cout << "|" << std::endl;
	for (index = 0; index < 8 ; index++)
		_contacts[index].printContactOnlyName(index);
	index = setIndex();
	if (index < 0)
		return ;
	_contacts[index].printContactAll(index);
}

void	PhoneBook::add(void)
{
	std::cout << "Set In The #" << _index << " Index Contact" << std::endl;
	_contacts[_index++].setContact();
	if (_index == 8)
		_index = 0;
}

static int	setIndex()
{
	std::string	new_str;
	int			index;

	while (1)
	{
		std::cout << "ENTER THE INDEX OF THE CONTACT YOU WANT TO SEE: ";
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

static void	printPrefixFieldName(const std::string& name)
{
	std::cout << "|" << std::setw(10) << name;
}
