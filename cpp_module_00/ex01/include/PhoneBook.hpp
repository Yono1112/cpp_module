#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include "Contact.hpp"

class PhoneBook
{
	public:
		void	add(Contact *contact);
		void	search(Contact contact);
};

#endif
