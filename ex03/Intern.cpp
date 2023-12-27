#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Intern Default Constructor Called" << std::endl;
}

Intern::~Intern()
{
	std::cout << "Intern Destructor Called" << std::endl;
}

AForm*	Intern::makeForm(const std::string& name, const std::string& target)
{
	std::string	form_list[3] = {"shrubbery creation", "robotomy request", "president pardon"};
	AForm*	obj;
	int	i;

	for (i = 0; i < 3; i++)
	{
		if (form_list[i] == name)
			break;
	}
	switch (i)
	{
		case 0:
			obj = new ShrubberyCreationForm(target);
			break ;
		case 1:
			obj = new RobotomyRequestForm(target);
			break ;
		case 2:
			obj = new PresidentialPardonForm(target);
			break ;
		default:
			throw "the form name passed as parameter doesn’t exist";
	}
	std::cout << "Intern creates " << form_list[i] << std::endl;
	return (obj);
}
