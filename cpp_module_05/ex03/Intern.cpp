#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Intern Default Constructor Called" << std::endl;
}

Intern::~Intern()
{
	std::cout << "Intern Destructor Called" << std::endl;
}

AForm*	createShrubberyCreationForm(const std::string& target)
{
	return (new ShrubberyCreationForm(target));
}

AForm*	createRobotRequestForm(const std::string& target)
{
	return (new RobotRequestForm(target));
}

AForm*	createPresidentialPardonForm(const std::string& target)
{
	return (new PresidentialPardonForm(target));
}

AForm*	Intern::makeForm(const std::string& name, const std::string& target)
{
	// AForm*	obj;
	typedef AForm*	(AForm::*formName)(const std::string&);
	formName	form_ptr[3] = {&createShrubberyCreationForm, &createRobotRequestForm, &createPresidentialPardonForm};
	// AForm*	(AForm::*form_ptr)(const std::string&)[3] = {&createShrubberyCreationForm, &createRobotRequestForm, &createPresidentialPardonForm};
	std::string	form_names[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};

	int	index = (name == form_names[0]) * 1
				+ (name == form_names[1]) * 2
				+ (name == form_names[2]) * 3;
	if (index == 0)
		throw "the form name passed as parameter doesn't exit";
	return ((this->*form_ptr[index])(target));
}
