#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm()
	: _name("default")
	, _is_signed(false)
	, _required_sign_grade(150)
	, _required_execute_grade(150)
{
	std::cout << "AForm Default Constructor Called" << std::endl;
}

AForm::~AForm()
{
	std::cout << "AForm Destructor Called" << std::endl;
}

AForm::AForm(const std::string& name, const bool& is_signed, const int& required_sign_grade, const int& required_execute_grade)
	: _name(name)
	, _is_signed(is_signed)
	, _required_sign_grade(required_sign_grade)
	, _required_execute_grade(required_execute_grade)
{
	std::cout << "AForm Argument Constructor Called" << std::endl;
	if (required_sign_grade < 1 || required_execute_grade < 1) {
		throw GradeTooHighException("ERROR: AForm Argument Constructor: Grade Is Too High");
	} else if (required_sign_grade > 150 || required_execute_grade > 150) {
		throw GradeTooLowException("ERROR: AForm Argument Constructor: Grade Is Too Low");
	}
}

AForm::AForm(const AForm& other)
	: _name(other._name)
	, _is_signed(other._is_signed)
	, _required_sign_grade(other._required_sign_grade)
	, _required_execute_grade(other._required_execute_grade)
{
	std::cout << "AForm Copy Constructor Called" << std::endl;
	if (other._required_sign_grade < 1 || other._required_execute_grade < 1) {
		throw GradeTooHighException("ERROR: AForm Copy Constructor: Grade Is Too High");
	} else if (other._required_sign_grade > 150 || other._required_execute_grade > 150) {
		throw GradeTooLowException("ERROR: AForm Copy Constructor: Grade Is Too Low");
	}
}

AForm&	AForm::operator=(const AForm& other)
{
	std::cout << "AForm Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		if (other._required_sign_grade < 1 || other._required_execute_grade < 1) {
			throw GradeTooHighException("ERROR: AForm Copy assignment operator: Grade Is Too High");
		} else if (other._required_sign_grade > 150 || other._required_execute_grade > 150) {
			throw GradeTooLowException("ERROR: AForm Copy assignment operator: Grade Is Too Low");
		}
		// this->_name = other._name;
		this->_is_signed = other._is_signed;
		// this->_required_sign_grade = other._required_sign_grade;
		// this->_required_execute_grade = other._required_execute_grade;
	}
	return (*this);
}

std::ostream&	operator<<(std::ostream& stream, const AForm& other)
{
	stream << "AForm name: " << other.getName()
		<< ", AForm is_signed: " << other.getIsSigned()
		<< ", AForm _required_sign_grade: " << other.getRequiredSignGrade()
		<< ", AForm required_execute_grade: " << other.getRequiredExecuteGrade();
	return (stream);
}

std::string	AForm::getName(void) const
{
	return (this->_name);
}

std::string	AForm::getIsSigned(void) const
{
	return (this->_is_signed ? "True" : "False");
}

int	AForm::getRequiredSignGrade(void) const
{
	return (this->_required_sign_grade);
}

int	AForm::getRequiredExecuteGrade(void) const
{
	return (this->_required_execute_grade);
}

void	AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (this->_is_signed == true) {
		throw "this form is already signed";
	} else {
		if (this->_required_sign_grade < bureaucrat.getGrade()) {
			throw AForm::GradeTooLowException("grade is too low");
		} else {
			this->_is_signed = true;
		}
	}
}

AForm::GradeTooHighException::GradeTooHighException(std::string message)
	: _error_message(message)
{
}

const char*	AForm::GradeTooHighException::what(void) const throw()
{
	return (_error_message.c_str());
}

AForm::GradeTooLowException::GradeTooLowException(std::string message)
	: _error_message(message)
{
}

const char*	AForm::GradeTooLowException::what(void) const throw()
{
	return (_error_message.c_str());
}
