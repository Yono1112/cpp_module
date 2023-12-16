#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
	: AForm(target, false, 25, 5)
{
	std::cout << "PresidentialPardonForm Argument Constructor Called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm Destructor Called" << std::endl;
}

void	PresidentialPardonForm::execute(Bureaucrat const& executor) const
{
	std::cout << "PresidentialPardonForm Hello " << executor.getName() << "!" << std::endl;
	std::cout << "Good news! " << executor.getName() << " has received a pardon form Zaphod Beeblebrox(a fictional character in 'The Hichhiker's Guide to the Galaxy')." << std::endl;
}