#ifndef CONTACT_H
# define CONTACT_H

#include <string>

class Contact
{
	public:
		void setNum(int new_num);
		int getNum(void);
		void setContact(void);
		void printContact(void);
		std::string getFirstName(void);
	private:
		int num;
		std::string first_name;
		std::string last_name;
		std::string nick_name;
		std::string phone_number;
		std::string darkest_secret;
};

#endif
