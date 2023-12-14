#include "ShrubberyCreationForm.hpp"
#include <iomanip>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	: AForm(target, false, 145, 137)
{
	std::cout << "ShrubberyCreationForm Argument Constructor Called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm Destructor Called" << std::endl;
}

void	ShrubberyCreationForm::execute(Bureaucrat const& executor) const
{
	std::cout << "ShrubberyCreationForm Hello " << executor.getName() << "!" << std::endl;
    	int padding = 9;
	for (int i = 1; i <= 15; i += 2) {
		std::cout << std::setw(padding--);
		for (int j = 0; j < i; j++) {
		    std::cout << 'X';
		}
		std::cout << std::endl;
	}
	std::cout << std::setw(10) << "###" << std::endl;
	std::cout << std::setw(10) << "###" << std::endl;
	std::cout << std::setw(11) << "#####" << std::endl;
	std::cout << std::setw(16) << "HAPPY HOLLIDAYS" << std::endl;
}
