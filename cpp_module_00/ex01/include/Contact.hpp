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
		std::string getFirstName(void);
	private:
		// int num;
		std::string first_name;
		std::string last_name;
		std::string nick_name;
		std::string phone_number;
		std::string darkest_secret;
};

bool	isOnlyDigit(std::string str);

#endif
