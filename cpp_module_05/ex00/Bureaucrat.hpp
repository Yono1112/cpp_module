#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>

class Bureaucrat
{
	public:
		Bureaucrat();
		~Bureaucrat();
		Bureaucrat(const std::string& name, const int& grade);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other);
		void		setName(const std::string& name);
		void		setGrade(const int& name);
		std::string	getName(void) const;
		int			getGrade(void) const;
	private:
		std::string	_name;
		int			_grade;
		void		GradeTooHighException(void) const;
		void		GradeTooLowException(void) const;
};

std::ostream&	operator<<(std::ostream& stream, const Bureaucrat& other);
#endif