#include "RobotRequestForm.hpp"
#include <cstdlib>

RobotRequestForm::RobotRequestForm(const std::string& target)
	: AForm(target, false, 72, 45)
{
	std::cout << "RobotRequestForm Argument Constructor Called" << std::endl;
}

RobotRequestForm::~RobotRequestForm()
{
	std::cout << "RobotRequestForm Destructor Called" << std::endl;
}

RobotRequestForm::RobotRequestForm(const RobotRequestForm& other)
	: AForm(other._name, other._is_signed, other._required_sign_grade, other._required_execute_grade)
{
	std::cout << "RobotRequestForm Copy Constructor Called" << std::endl;
}

RobotRequestForm&	RobotRequestForm::operator=(const RobotRequestForm& other)
{
	std::cout << "RobotRequestForm Copy assignment operator called" << std::endl;
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

void	RobotRequestForm::execute(Bureaucrat const& executor) const
{
	std::cout << "RobotRequestForm Hello " << executor.getName() << "!" << std::endl;
	std::cout << "Drilling noise: Brrrrrr..." << std::endl;
	std::srand(time(NULL));
	if (rand() % 2 == 0)
		std::cout << "Success on " << executor.getName() << "!" << std::endl;
	else
		std::cout << "Failure on " << executor.getName() << "." << std::endl;
}
