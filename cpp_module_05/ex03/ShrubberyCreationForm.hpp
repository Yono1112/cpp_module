#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <string>

class ShrubberyCreationForm: public AForm
{
	public:
		ShrubberyCreationForm(const std::string& target);
		~ShrubberyCreationForm();
		void	execute(Bureaucrat const& executor) const;
	private:
};

#endif