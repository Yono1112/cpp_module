#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
	public:
		PhoneBook();
		~PhoneBook();
		void	add(void);
		void	search(void);
	private:
		Contact	contacts[8];
		int	index;
};

#endif
