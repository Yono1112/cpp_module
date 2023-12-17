#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

void	test_invalid_ShrubberyCreationForm()
{
	std::cout << "==========================================" << std::endl;
	std::cout << "run test_invalid_ShrubberyCreationForm" << std::endl;
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

void	test_valid_ShrubberyCreationForm()
{
	std::cout << "==========================================" << std::endl;
	std::cout << "run test_valid_ShrubberyCreationForm" << std::endl;
	try
	{
		Bureaucrat				president("president", 3);
		ShrubberyCreationForm	form1("form1");

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

void	test_invalid_RobotRequestForm()
{
	std::cout << "==========================================" << std::endl;
	std::cout << "run test_invalid_RobotRequestForm" << std::endl;
	try
	{
		Bureaucrat				president("president", 3);
		RobotRequestForm	form1("form1");

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

void	test_valid_RobotRequestForm()
{
	std::cout << "==========================================" << std::endl;
	std::cout << "run test_valid_RobotRequestForm" << std::endl;
	try
	{
		Bureaucrat				president("president", 3);
		RobotRequestForm	form1("form1");

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

void	test_invalid_PresidentialPardonForm()
{
	std::cout << "==========================================" << std::endl;
	std::cout << "run test_invalid_PresidentialPardonForm" << std::endl;
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

void	test_valid_PresidentialPardonForm()
{
	std::cout << "==========================================" << std::endl;
	std::cout << "run test_valid_PresidentialPardonForm" << std::endl;
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

void	test_invalid_intern()
{	std::cout << "==========================================" << std::endl;
	std::cout << "run test_valid_intern" << std::endl;
	try
	{
		Bureaucrat	president("president", 3);
		Intern  	someRandomIntern;
		AForm*   	rrf;

		rrf = someRandomIntern.makeForm("undefined form", "Bender");
		president.signForm(*rrf);
		president.executeForm(*rrf);
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

void	test_valid_intern()
{
	std::cout << "==========================================" << std::endl;
	std::cout << "run test_valid_intern" << std::endl;
	try
	{
		Bureaucrat	president("president", 3);
		Intern  	someRandomIntern;
		AForm*   	rrf;

		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		president.signForm(*rrf);
		president.executeForm(*rrf);
		rrf = someRandomIntern.makeForm("president pardon", "Bender");
		president.signForm(*rrf);
		president.executeForm(*rrf);
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
	// test_invalid_ShrubberyCreationForm();
	// test_valid_ShrubberyCreationForm();
	// test_invalid_RobotRequestForm();
	// test_valid_RobotRequestForm();
	// test_invalid_PresidentialPardonForm();
	// test_valid_PresidentialPardonForm();
	test_invalid_intern();
	test_valid_intern();
	return (0);
}
