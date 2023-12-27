#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	public:
		AForm();
		virtual ~AForm();
		AForm(const std::string& name, const bool& is_signed, const int& required_sign_grade, const int& required_execute_grade);
		AForm(const AForm& other);
		AForm&	operator=(const AForm& other);
		void	beSigned(const Bureaucrat& bureaucrat);
		virtual void	execute(Bureaucrat const& executor) const = 0;
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
	protected:
		const std::string	_name;
		bool				_is_signed;
		const int			_required_sign_grade;
		const int			_required_execute_grade;
};

std::ostream&	operator<<(std::ostream& stream, const AForm& other);
#endif
