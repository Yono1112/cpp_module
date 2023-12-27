#include "Bureaucrat.hpp"
#include "Form.hpp"

void testFormConstructors()
{
	std::cout << "Testing Form Constructors..." << std::endl;
	try
	{
		Form form1;
		Form form2("Form2", false, 30, 50);
		Form form3(form2);
		form1 = form3;

		std::cout << form1 << std::endl;
		std::cout << form2 << std::endl;
		std::cout << form3 << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
}

void testSignSuccess()
{
	std::cout << "=========================================" << std::endl;
	std::cout << "Testing Sign Success..." << std::endl;
	try
	{
		Bureaucrat bureaucrat("John", 10);
		Form form("Form", false, 20, 40);

		std::cout << bureaucrat << ", bureaucrat grade " << bureaucrat.getGrade() << "." << std::endl;
		std::cout << form << std::endl;
		bureaucrat.signForm(form);
		std::cout << form << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
}

void testSignFailure()
{
	std::cout << "=========================================" << std::endl;
	std::cout << "Testing Sign Failure..." << std::endl;
	try
	{
		Bureaucrat bureaucrat("Doe", 50);
		Form form("Form", false, 10, 20);

		std::cout << bureaucrat << ", bureaucrat grade " << bureaucrat.getGrade() << "." << std::endl;
		std::cout << form << std::endl;
		bureaucrat.signForm(form);
		std::cout << form << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
}

void testUpgradeAndSign()
{
	std::cout << "=========================================" << std::endl;
	std::cout << "Testing Upgrade and Sign..." << std::endl;
	try
	{
		Bureaucrat bureaucrat("Jane", 50);
		Form form("Form", false, 45, 50);

		std::cout << bureaucrat << ", bureaucrat grade " << bureaucrat.getGrade() << "." << std::endl;
		std::cout << form << std::endl;
		bureaucrat.signForm(form);
		while (bureaucrat.getGrade() > 45) {
			bureaucrat.upGrade();
			std::cout << bureaucrat << ", bureaucrat grade " << bureaucrat.getGrade() << "." << std::endl;
		}
		bureaucrat.signForm(form);
		std::cout << form << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
}

void testDowngradeAndFailToSign()
{
	std::cout << "=========================================" << std::endl;
	std::cout << "Testing Downgrade and Fail to Sign..." << std::endl;
	try
	{
		Bureaucrat bureaucrat("Max", 20);
		Form form1("Form1", false, 20, 20);
		Form form2(form1);

		std::cout << bureaucrat << ", bureaucrat grade " << bureaucrat.getGrade() << "." << std::endl;
		std::cout << form1 << std::endl;
		std::cout << form2 << std::endl;
		bureaucrat.signForm(form1);
		bureaucrat.downGrade();
		bureaucrat.signForm(form2);
		std::cout << form1 << std::endl;
		std::cout << form2 << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
}

void testEdgeCases()
{
	std::cout << "=========================================" << std::endl;
	std::cout << "Testing Edge Cases..." << std::endl;
	try
	{
		Bureaucrat high("High", 0);
		std::cout << high << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat low("Low", 151);
		std::cout << low << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
}

int main()
{
	testFormConstructors();
	testSignSuccess();
	testSignFailure();
	testUpgradeAndSign();
	testDowngradeAndFailToSign();
	testEdgeCases();
	return (0);
}
