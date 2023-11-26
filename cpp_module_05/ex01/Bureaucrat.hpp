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
		std::string	getName(void) const;
		int			getGrade(void) const;
		void		upGrade(void);
		void		downGrade(void);
		void		signForm(void);
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
		int			_grade;
};

std::ostream&	operator<<(std::ostream& stream, const Bureaucrat& other);
#endif