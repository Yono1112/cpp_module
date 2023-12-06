#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	try {
		Bureaucrat				president("president", 1);
		ShrubberyCreationForm	form1("form1");

		president.executeForm(form1);
	} catch (const std::exception& e) {
		std::cerr << "Exception caught in main: " << e.what() << std::endl;
	}
	return (0);
}
