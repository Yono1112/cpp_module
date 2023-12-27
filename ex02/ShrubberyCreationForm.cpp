#include "ShrubberyCreationForm.hpp"
#include <iomanip>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	: AForm(target, false, 145, 137)
{
	std::cout << "ShrubberyCreationForm Argument Constructor Called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm Destructor Called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
	: AForm(other._name, other._is_signed, other._required_sign_grade, other._required_execute_grade)
{
	std::cout << "ShrubberyCreationForm Copy Constructor Called" << std::endl;
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	std::cout << "ShrubberyCreationForm Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		if (other._required_sign_grade < 1 || other._required_execute_grade < 1) {
			throw GradeTooHighException("ERROR: AForm Copy assignment operator: Grade Is Too High");
		} else if (other._required_sign_grade > 150 || other._required_execute_grade > 150) {
			throw GradeTooLowException("ERROR: AForm Copy assignment operator: Grade Is Too Low");
		}
		this->_is_signed = other._is_signed;
	}
	return (*this);
}

void	writeAsciiTree(std::ofstream& ofs)
{
   	int padding = 9;
	for (int i = 1; i <= 15; i += 2) {
		ofs << std::setw(padding--);
		for (int j = 0; j < i; j++) {
		    ofs << "X";
		}
		ofs << std::endl;
	}
	ofs << std::setw(10) << "###" << std::endl;
	ofs << std::setw(10) << "###" << std::endl;
	ofs << std::setw(11) << "#####" << std::endl;
	ofs << std::setw(16) << "HAPPY HOLLIDAYS" << std::endl;
}

void	ShrubberyCreationForm::execute(Bureaucrat const& executor) const
{
	std::cout << "ShrubberyCreationForm Hello " << executor.getName() << "!" << std::endl;
	std::ofstream	ofs(executor.getName() + "_shrubbery");
	if (ofs.fail())
		throw "cannot open file";
	writeAsciiTree(ofs);
	ofs.close();
	std::cout << "write successfully!" << std::endl;
}
