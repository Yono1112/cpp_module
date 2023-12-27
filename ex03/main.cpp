#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
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

void	test_invalid_RobotomyRequestForm()
{
	std::cout << "==========================================" << std::endl;
	std::cout << "run test_invalid_RobotomyRequestForm" << std::endl;
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

void	test_valid_RobotomyRequestForm()
{
	std::cout << "==========================================" << std::endl;
	std::cout << "run test_valid_RobotomyRequestForm" << std::endl;
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
		delete rrf;
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
		AForm*   	rrf1;
		AForm*   	rrf2;

		rrf1 = someRandomIntern.makeForm("robotomy request", "Bender");
		president.signForm(*rrf1);
		president.executeForm(*rrf1);
		rrf2 = someRandomIntern.makeForm("president pardon", "Bender");
		president.signForm(*rrf2);
		president.executeForm(*rrf2);
		delete rrf1;
		delete rrf2;
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
	// test_invalid_RobotomyRequestForm();
	// test_valid_RobotomyRequestForm();
	// test_invalid_PresidentialPardonForm();
	// test_valid_PresidentialPardonForm();
	test_invalid_intern();
	test_valid_intern();
	return (0);
}

// __attribute__((destructor))
// static void	destructor(void)
// {
// 	system("leaks -q bureaucrat");
// }