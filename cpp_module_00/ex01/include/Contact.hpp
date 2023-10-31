#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>

class Contact
{
	public:
		// void setNum(int new_num);
		// int getNum(void);
		Contact();
		~Contact();
		void setContact(void);
		void printContactOnlyName(int index);
		void printContactAll(int index);
	private:
		// int num;
		std::string _first_name;
		std::string _last_name;
		std::string _nick_name;
		std::string _phone_number;
		std::string _darkest_secret;
};

bool	isOnlyDigit(std::string str);

#endif
