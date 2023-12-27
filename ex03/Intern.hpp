#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <string>

class Intern
{
	public:
		Intern();
		~Intern();
		AForm*	makeForm(const std::string& name, const std::string& target);
	private:
};

#endif
