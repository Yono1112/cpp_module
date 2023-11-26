#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
	: _name("default")
	, _grade(150)
{
	std::cout << "Bureaucrat Default Constructor Called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name, const int& grade)
	: _name(name)
	, _grade(grade)
{
	std::cout << "Bureaucrat Argument Constructor Called" << std::endl;
	if (grade < 1) {
		throw GradeTooHighException("Grade Is Too High");
	} else if (grade > 150) {
		throw GradeTooLowException("Grade Is Too Low");
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
	: _name(other._name)
	, _grade(other._grade)
{
	std::cout << "Bureaucrat Copy Constructor Called" << std::endl;
	if (other._grade < 1) {
		throw GradeTooHighException("Grade Is Too High");
	} else if (other._grade > 150) {
		throw GradeTooLowException("Grade Is Too Low");
	}
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		if (other._grade < 1) {
			throw GradeTooHighException("Grade Is Too High");
		} else if (other._grade > 150) {
			throw GradeTooLowException("Grade Is Too Low");
		}
		this->_grade = other._grade;
	}
	return (*this);
}

std::ostream&	operator<<(std::ostream& stream, const Bureaucrat& other)
{
	stream << other.getName();
	return (stream);
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat Destructor Called" << std::endl;
}

std::string	Bureaucrat::getName(void) const
{
	return (_name);
}

int	Bureaucrat::getGrade(void) const
{
	return (_grade);
}

void	Bureaucrat::upGrade(void)
{
	int	result;

	result = this->_grade;
	if (--result < 1) {
		throw GradeTooHighException("Grade Is Too High");
	} else {
		this->_grade = result;
	}
}

void	Bureaucrat::downGrade(void)
{
	int	result;

	result = this->_grade;
	if (++result > 150) {
		throw GradeTooLowException("Grade Is Too Low");
	} else {
		this->_grade = result;
	}
}

Bureaucrat::GradeTooHighException::GradeTooHighException(std::string message)
	: _error_message(message)
{
}

const char*	Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return (_error_message.c_str());
}

Bureaucrat::GradeTooLowException::GradeTooLowException(std::string message)
	: _error_message(message)
{
}

const char*	Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return (_error_message.c_str());
}
