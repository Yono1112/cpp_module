#include "Contact.hpp"
static std::string	toString(const int& num);
static std::string	setMemberValue(const std::string& member_name, bool flag_num);
static bool	isSpaceOrEmpty(const std::string& str);

Contact::Contact() 
	: _first_name("None")
	, _last_name("None")
	, _nick_name("None")
	, _phone_number("None")
	, _darkest_secret("None")
{
	// std::cout << "Contact con" << std::endl;
}

Contact::~Contact()
{
	// std::cout << "Contact des" << std::endl;
}

void	Contact::setContact(void)
{
	_first_name = setMemberValue("First Name: ", false);
	if (_first_name == "")
		return ;
	_last_name = setMemberValue("Last Name: ", false);
	if (_last_name == "")
		return ;
	_nick_name = setMemberValue("Nick Name: ", false);
	if (_last_name == "")
		return ;
	_phone_number = setMemberValue("Phone Number: ", true);
	if (_phone_number == "")
		return ;
	_darkest_secret = setMemberValue("Darkest Secret: ", false);
	if (_darkest_secret == "")
		return ;
}

void	Contact::printContactOnlyName(int index)
{
	printTrimedField(toString(index));
	printTrimedField(_first_name);
	printTrimedField(_last_name);
	printTrimedField(_nick_name);
	std::cout << "|" << std::endl;
} 

void	Contact::printContactAll(int index)
{
	printField("Index", toString(index));
	printField("FirstName", _first_name);
	printField("LastName", _last_name);
	printField("NickName", _nick_name);
	printField("PhoneNum", _phone_number);
	printField("Secret", _darkest_secret);
}

void	Contact::printField(const std::string& name, const std::string& value)
{
	std::cout << std::setw(10) << name << ": " << value << std::endl;
}

std::string	Contact::trimToNineAndAddDot(std::string str)
{
	if (str.length() > 10)
	{
		while (str.length() > 9)
			str.erase(str.length() - 1);
		str.push_back('.');
	}
	return (str);
}

void	Contact::printTrimedField(const std::string& value)
{
	std::cout << "|" << std::setw(10) << trimToNineAndAddDot(value);
}

bool	isOnlyDigit(const std::string& str)
{
	if (str.length() == 0)
		return (false);
	for (int i = 0; i < (int)str.length() ; i++) {
		if (!std::isdigit(str[i]))
			return (false);
	}
	return (true);
}

static bool	isSpaceOrEmpty(const std::string& str)
{
	if (str.length() == 0)
		return (true);
	for (int i = 0; i < (int)str.length() ; i++) {
		if (str[i] != ' ' && str[i] != '\t')
			return (false);
	}
	return (true);
}

static std::string	setMemberValue(const std::string& member_name, bool flag_num)
{
	std::string	new_str;

	while (1)
	{
		std::cout << "Enter " << member_name;
		if (!std::getline(std::cin, new_str))
			return ("");
		if (flag_num && !isOnlyDigit(new_str))
		{
			std::cout << "You Must Enter Only Number" << std::endl;
			continue ;
		}
		if (!isSpaceOrEmpty(new_str))
			break ;
		std::cout << "You Must Enter At Least One Character" << std::endl;
	}
	return (new_str);
}

static std::string	toString(const int& num)
{
	std::stringstream	ss;
	ss << num;
	return (ss.str());
}
