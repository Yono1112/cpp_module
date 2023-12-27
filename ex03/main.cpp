#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

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

void	testInvalidIntern()
{	std::cout << "==========================================" << std::endl;
	std::cout << "run testInvalidIntern" << std::endl;
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

void	testValidIntern()
{
	std::cout << "==========================================" << std::endl;
	std::cout << "run testValidIntern" << std::endl;
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
	// testInvalidShrubberyCreationForm();
	// testValidShrubberyCreationForm();
	// testInvalidRobotomyRequestForm();
	// testValidRobotomyRequestForm();
	// testInvalidPresidentialPardonForm();
	// testValidPresidentialPardonForm();
	testInvalidIntern();
	testValidIntern();
	return (0);
}

// __attribute__((destructor))
// static void	destructor(void)
// {
// 	system("leaks -q bureaucrat");
// }
