#include "Bureaucrat.hpp"
#include "Form.hpp"

void testFormConstructors()
{
	std::cout << "Testing Form Constructors..." << std::endl;
	Form form1;
	Form form2("Form2", false, 30, 50);
	Form form3(form2);
	form1 = form3;

	std::cout << form1 << std::endl;
	std::cout << form2 << std::endl;
	std::cout << form3 << std::endl;
}

void testSignSuccess()
{
	std::cout << "=========================================" << std::endl;
	std::cout << "Testing Sign Success..." << std::endl;
	Bureaucrat bureaucrat("John", 10);
	Form form("Form", false, 20, 40);

	std::cout << bureaucrat << std::endl;
	bureaucrat.signForm(form);
	std::cout << form << std::endl;
}

void testSignFailure()
{
	std::cout << "=========================================" << std::endl;
	std::cout << "Testing Sign Failure..." << std::endl;
	Bureaucrat bureaucrat("Doe", 50);
	Form form("Form", false, 10, 20);

	std::cout << bureaucrat << std::endl;
	std::cout << form << std::endl;
	bureaucrat.signForm(form);
}

void testUpgradeAndSign()
{
	std::cout << "=========================================" << std::endl;
	std::cout << "Testing Upgrade and Sign..." << std::endl;
	Bureaucrat bureaucrat("Jane", 50);
	Form form("Form", false, 45, 50);

	bureaucrat.signForm(form);
	std::cout << bureaucrat << std::endl;
	std::cout << form << std::endl;
	while (bureaucrat.getGrade() > 45) {
		bureaucrat.upGrade();
	}
	bureaucrat.signForm(form);
	std::cout << form << std::endl;
}

void testDowngradeAndFailToSign()
{
	std::cout << "=========================================" << std::endl;
	std::cout << "Testing Downgrade and Fail to Sign..." << std::endl;
	Bureaucrat bureaucrat("Max", 20);
	Form form1("Form1", false, 20, 20);
	Form form2("Form2", false, 20, 20);

	std::cout << bureaucrat << std::endl;
	std::cout << form1 << std::endl;
	std::cout << form2 << std::endl;
	bureaucrat.signForm(form1);
	bureaucrat.downGrade();
	bureaucrat.signForm(form2);
	std::cout << form1 << std::endl;
	std::cout << form2 << std::endl;
}

void testEdgeCases()
{
	std::cout << "=========================================" << std::endl;
	std::cout << "Testing Edge Cases..." << std::endl;
	try {
		Bureaucrat high("High", 0);
		std::cout << high << std::endl;
	} catch (const std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	try {
		Bureaucrat low("Low", 151);
		std::cout << low << std::endl;
	} catch (const std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
}

int main()
{
	try {
		testFormConstructors();
		testSignSuccess();
		testSignFailure();
		testUpgradeAndSign();
		testDowngradeAndFailToSign();
		testEdgeCases();
	} catch (const std::exception& e) {
		std::cerr << "Exception caught in main: " << e.what() << std::endl;
	}
	return (0);
}
