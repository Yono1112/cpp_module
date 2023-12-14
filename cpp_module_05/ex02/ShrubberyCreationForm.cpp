#include "ShrubberyCreationForm.hpp"

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
}
