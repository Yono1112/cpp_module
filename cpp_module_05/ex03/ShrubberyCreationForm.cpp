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
}
