#include "RobotomyRequestForm.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
	: AForm(target, false, 72, 45)
{
	std::cout << "RobotomyRequestForm Argument Constructor Called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm Destructor Called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
	: AForm(other._name, other._is_signed, other._required_sign_grade, other._required_execute_grade)
{
	std::cout << "RobotomyRequestForm Copy Constructor Called" << std::endl;
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	std::cout << "RobotomyRequestForm Copy assignment operator called" << std::endl;
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

void	RobotomyRequestForm::execute(Bureaucrat const& executor) const
{
	std::cout << "RobotomyRequestForm Hello " << executor.getName() << "!" << std::endl;
	std::cout << "Drilling noise: Brrrrrr..." << std::endl;
	std::srand(time(NULL));
	if (rand() % 2 == 0)
		std::cout << "Success on " << executor.getName() << "!" << std::endl;
	else
		std::cout << "Failure on " << executor.getName() << "." << std::endl;
}
