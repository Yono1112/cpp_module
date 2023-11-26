#include "Bureaucrat.hpp"

void	testValidGrade(void)
{
	std::cout << "run testValidGrade" << std::endl;
	try
	{
		Bureaucrat	a("jim", 100);
		std::cout << a << ", bureaucrat grade " << a.getGrade() << "." << std::endl;
		std::cout << a << " is upGraded!" << std::endl;
		a.upGrade();
		std::cout << a << " is now " << a.getGrade() << "." << std::endl;
		std::cout << a << " is downGraded!" << std::endl;
		a.downGrade();
		std::cout << a << " is now " << a.getGrade() << "." << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Catch std::exception: " << e.what() << std::endl;
		return ;
	}
}

void	testCopyGrade(void)
{
	std::cout << "=========================================" << std::endl;
	std::cout << "run testCopyGrade" << std::endl;
	try
	{
		Bureaucrat	a("jim", 150);
		Bureaucrat	b(a);
		Bureaucrat	c;

		std::cout << a << ", bureaucrat grade " << a.getGrade() << "." << std::endl;
		std::cout << b << ", bureaucrat grade " << b.getGrade() << "." << std::endl;
		std::cout << c << ", bureaucrat grade " << c.getGrade() << "." << std::endl;
		c = b;
		std::cout << c << ", bureaucrat grade " << c.getGrade() << "." << std::endl;

		std::cout << b << " is upGraded!" << std::endl;
		b.upGrade();
		std::cout << b << " is now " << b.getGrade() << "." << std::endl;

		std::cout << c << " is downGraded!" << std::endl;
		c.downGrade();
		std::cout << c << " is now " << c.getGrade() << "." << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Catch std::exception: " << e.what() << std::endl;
		return ;
	}
}

void	testGradeTooHighException(void)
{
	std::cout << "=========================================" << std::endl;
	std::cout << "run testGradeTooHighException" << std::endl;
	try
	{
		Bureaucrat	a("jim", 1000);
		std::cout << a << ", bureaucrat grade " << a.getGrade() << "." << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Catch std::exception: " << e.what() << std::endl;
		return ;
	}
}

void	testGradeTooLowException(void)
{
	std::cout << "=========================================" << std::endl;
	std::cout << "run testGradeTooLowException" << std::endl;
	try
	{
		Bureaucrat	a("jim", -1);
		std::cout << a << ", bureaucrat grade " << a.getGrade() << "." << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Catch std::exception: " << e.what() << std::endl;
		return ;
	}
}

void	testInvalidUpGrade(void)
{
	std::cout << "=========================================" << std::endl;
	std::cout << "run testInvalidUpGrade" << std::endl;
	try
	{
		Bureaucrat	a("jim", 1);
		std::cout << a << ", bureaucrat grade " << a.getGrade() << "." << std::endl;
		std::cout << a << " is upGraded!" << std::endl;
		a.upGrade();
		std::cout << a << " is now " << a.getGrade() << "." << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Catch std::exception: " << e.what() << std::endl;
		return ;
	}
}

void	testInvalidDownGrade(void)
{
	std::cout << "=========================================" << std::endl;
	std::cout << "run testInvalidDownGrade" << std::endl;
	try
	{
		Bureaucrat	a("jim", 150);
		std::cout << a << ", bureaucrat grade " << a.getGrade() << "." << std::endl;
		std::cout << a << " is downGraded!" << std::endl;
		a.downGrade();
		std::cout << a << " is now " << a.getGrade() << "." << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Catch std::exception: " << e.what() << std::endl;
		return ;
	}
}

int	main(void)
{
	testValidGrade();
	testCopyGrade();
	testGradeTooHighException();
	testGradeTooLowException();
	testInvalidUpGrade();
	testInvalidDownGrade();
	return (0);
}