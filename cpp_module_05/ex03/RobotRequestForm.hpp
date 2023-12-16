#ifndef ROBOTREQUESTFORM_HPP
#define ROBOTREQUESTFORM_HPP

#include "AForm.hpp"
#include <string>

class RobotRequestForm: public AForm
{
	public:
		RobotRequestForm(const std::string& target);
		~RobotRequestForm();
		void	execute(Bureaucrat const& executor) const;
	private:
};

#endif