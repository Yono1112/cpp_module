#include "RobotRequestForm.hpp"

RobotRequestForm::RobotRequestForm(const std::string& target)
	: AForm(target, false, 72, 45)
{
	std::cout << "RobotRequestForm Argument Constructor Called" << std::endl;
}

RobotRequestForm::~RobotRequestForm()
{
	std::cout << "RobotRequestForm Destructor Called" << std::endl;
}

void	RobotRequestForm::execute(Bureaucrat const& executor) const
{
	std::cout << "RobotRequestForm Hello " << executor.getName() << "!" << std::endl;
}
