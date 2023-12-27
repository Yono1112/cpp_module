#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
	: AForm("default", false, 25, 5)
{
	std::cout << "PresidentialPardonForm Default Constructor Called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
	: AForm(target, false, 25, 5)
{
	std::cout << "PresidentialPardonForm Argument Constructor Called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm Destructor Called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
	: AForm(other._name, other._is_signed, other._required_sign_grade, other._required_execute_grade)
{
	std::cout << "PresidentialPardonForm Copy Constructor Called" << std::endl;
}

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	std::cout << "PresidentialPardonForm Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		if (other._required_sign_grade < 1 || other._required_execute_grade < 1) {
			throw GradeTooHighException("ERROR: AForm Copy assignment operator: Grade Is Too High");
		} else if (other._required_sign_grade > 150 || other._required_execute_grade > 150) {
			throw GradeTooLowException("ERROR: AForm Copy assignment operator: Grade Is Too Low");
		}
		this->_is_signed = other._is_signed;
	}
	return (*this);
}

void	PresidentialPardonForm::execute(Bureaucrat const& executor) const
{
	std::cout << "PresidentialPardonForm Hello " << executor.getName() << "!" << std::endl;
	std::cout << "Good news! " << executor.getName() << " has received a pardon form Zaphod Beeblebrox(a fictional character in 'The Hichhiker's Guide to the Galaxy')." << std::endl;
}
