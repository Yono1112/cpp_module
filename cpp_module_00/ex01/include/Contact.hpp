#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <cstring>
#include <sstream>

class Contact
{
	public:
		Contact();
		~Contact();
		void	setContact(void);
		void	printContactOnlyName(int index);
		void	printContactAll(int index);
	private:
		void		printField(const std::string& name, const std::string& value);
		void		printTrimedField(const std::string& value);
		std::string	trimToNineAndAddDot(std::string str);
		std::string _first_name;
		std::string _last_name;
		std::string _nick_name;
		std::string _phone_number;
		std::string _darkest_secret;
};

bool	isOnlyDigit(const std::string& str);

#endif
