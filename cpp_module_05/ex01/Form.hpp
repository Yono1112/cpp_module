#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Form
{
	public:
		Form();
		~Form();
		Form(const std::string& name, const bool& is_signed, const int& required_sign_grade, const int& required_execute_grade);
		Form(const Form& other);
		Form&	operator=(const Form& other);
		void	beSigned(const Form& other);
		std::string	getName(void) const;
		std::string	getIsSigned(void) const;
		int			getRequiredSignGrade(void) const;
		int			getRequiredExecuteGrade(void) const;
		class GradeTooHighException: public std::exception
		{
			public:
				GradeTooHighException(const std::string message);
				virtual const char* what(void) const throw();
				~GradeTooHighException() throw() {};
			private:
				std::string	_error_message;
		};
		class GradeTooLowException: public std::exception
		{
			public:
				GradeTooLowException(const std::string message);
				virtual const char* what(void) const throw();
				~GradeTooLowException() throw() {};
			private:
				std::string	_error_message;
		};
	private:
		std::string	_name;
		bool		_is_signed;
		int			_required_sign_grade;
		int			_required_execute_grade;
};

std::ostream&	operator<<(std::ostream& stream, const Form& other);
#endif