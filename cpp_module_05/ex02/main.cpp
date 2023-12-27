#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void	testInvalidShrubberyCreationForm()
{
	std::cout << "==========================================" << std::endl;
	std::cout << "run testInvalidShrubberyCreationForm" << std::endl;
	try
	{
		Bureaucrat				president("president", 3);
		ShrubberyCreationForm	form1("form1");

		president.executeForm(form1);
	}
	catch(const char* e)
	{
		std::cerr << "Exception caught in main: " << e << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception caught in main: " << e.what() << std::endl;
	}
	
}

void	testValidShrubberyCreationForm()
{
	std::cout << "==========================================" << std::endl;
	std::cout << "run testValidShrubberyCreationForm" << std::endl;
	try
	{
		Bureaucrat				president("president", 3);
		ShrubberyCreationForm	form1("form1");
		ShrubberyCreationForm	form2("form2");

		president.signForm(form1);
		president.executeForm(form1);
		form2 = form1;
		president.executeForm(form2);
	}
	catch(const char* e)
	{
		std::cerr << "Exception caught in main: " << e << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception caught in main: " << e.what() << std::endl;
	}
	
}

void	testInvalidRobotomyRequestForm()
{
	std::cout << "==========================================" << std::endl;
	std::cout << "run testInvalidRobotomyRequestForm" << std::endl;
	try
	{
		Bureaucrat				president("president", 3);
		RobotomyRequestForm	form1("form1");

		president.executeForm(form1);
	}
	catch(const char* e)
	{
		std::cerr << "Exception caught in main: " << e << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception caught in main: " << e.what() << std::endl;
	}
}

void	testValidRobotomyRequestForm()
{
	std::cout << "==========================================" << std::endl;
	std::cout << "run testValidRobotomyRequestForm" << std::endl;
	try
	{
		Bureaucrat				president("president", 3);
		RobotomyRequestForm	form1("form1");

		president.signForm(form1);
		president.executeForm(form1);
	}
	catch(const char* e)
	{
		std::cerr << "Exception caught in main: " << e << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception caught in main: " << e.what() << std::endl;
	}
}

void	testInvalidPresidentialPardonForm()
{
	std::cout << "==========================================" << std::endl;
	std::cout << "run testInvalidPresidentialPardonForm" << std::endl;
	try
	{
		Bureaucrat				president("president", 3);
		PresidentialPardonForm	form1("form1");

		president.executeForm(form1);
	}
	catch(const char* e)
	{
		std::cerr << "Exception caught in main: " << e << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception caught in main: " << e.what() << std::endl;
	}
}

void	testValidPresidentialPardonForm()
{
	std::cout << "==========================================" << std::endl;
	std::cout << "run testValidPresidentialPardonForm" << std::endl;
	try
	{
		Bureaucrat				president("president", 3);
		PresidentialPardonForm	form1("form1");

		president.signForm(form1);
		president.executeForm(form1);
	}
	catch(const char* e)
	{
		std::cerr << "Exception caught in main: " << e << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception caught in main: " << e.what() << std::endl;
	}
}

int main()
{
	testInvalidShrubberyCreationForm();
	testValidShrubberyCreationForm();
	testInvalidRobotomyRequestForm();
	testValidRobotomyRequestForm();
	testInvalidPresidentialPardonForm();
	testValidPresidentialPardonForm();
	return (0);
}
