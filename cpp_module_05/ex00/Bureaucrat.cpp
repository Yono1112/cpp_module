#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
	: _name("")
	, _grade(0)
{
	std::cout << "Bureaucrat Default Constructor Called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name, const int& grade)
	: _name(name)
	, _grade(grade)
{
	std::cout << "Bureaucrat Argument Constructor Called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
	: _name(other._name)
	, _grade(other._grade)
{
	std::cout << "Bureaucrat Copy Constructor Called" << std::endl;
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_name = other._name;
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

void		Bureaucrat::setName(const std::string& name)
{
	_name = name;
}

void		Bureaucrat::setGrade(const int& grade)
{
	_grade = grade;
}

std::string	Bureaucrat::getName(void) const
{
	return (_name);
}

int	Bureaucrat::getGrade(void) const
{
	return (_grade);
}