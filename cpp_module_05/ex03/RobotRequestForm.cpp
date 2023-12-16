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
