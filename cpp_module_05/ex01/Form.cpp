#include "Form.hpp"

Form::Form()
	: _name("default")
	, _is_signed(false)
	, _required_sign_grade(150)
	, _required_execute_grade(150)
{
	std::cout << "Form Default Constructor Called" << std::endl;
}

Form::~Form()
{
	std::cout << "Form Destructor Called" << std::endl;
}

Form::Form(const std::string& name, const bool& is_signed, const int& required_sign_grade, const int& required_execute_grade)
	: _name(name)
	, _is_signed(is_signed)
	, _required_sign_grade(required_sign_grade)
	, _required_execute_grade(required_execute_grade)
{
	std::cout << "Form Argument Constructor Called" << std::endl;
}

Form::Form(const Form& other)
	: _name(other._name)
	, _is_signed(other._is_signed)
	, _required_sign_grade(other._required_sign_grade)
	, _required_execute_grade(other._required_execute_grade)
{
	std::cout << "Form Copy Constructor Called" << std::endl;
}

Form&	Form::operator=(const Form& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_name = other._name;
		this->_is_signed = other._is_signed;
		this->_required_sign_grade = other._required_sign_grade;
		this->_required_execute_grade = other._required_execute_grade;
	}
	return (*this);
}

std::ostream&	operator<<(std::ostream& stream, const Form& other)
{
	stream << "Form name: " << other.getName()
		<< ", Form is_signed: " << other.getIsSigned()
		<< ", Form _required_sign_grade: " << other.getRequiredSignGrade()
		<< ", Form required_execute_grade: " << other.getRequiredExecuteGrade();
	return (stream);
}

std::string	Form::getName(void) const
{
	return (this->_name);
}

std::string	Form::getIsSigned(void) const
{
	return (this->_is_signed ? "True" : "False");
}

int	Form::getRequiredSignGrade(void) const
{
	return (this->_required_sign_grade);
}

int	Form::getRequiredExecuteGrade(void) const
{
	return (this->_required_execute_grade);
}
