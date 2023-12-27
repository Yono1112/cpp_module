#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>

class PhoneBook
{
	public:
		PhoneBook();
		~PhoneBook();
		void	add(void);
		void	search(void);
	private:
		Contact	_contacts[8];
		int		_index;
};

#endif