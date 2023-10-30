#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include "Contact.hpp"

class PhoneBook
{
	public:
		void	add(void);
		void	search(void);
	private:
		Contact	contacts[8];
};

#endif
