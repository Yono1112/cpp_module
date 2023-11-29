#include "Harl.hpp"

Harl::Harl()
{
}

Harl::~Harl()
{
}

void	Harl::complain(const std::string& level)
{
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	levelPtr	funcPtr[5] = {&Harl::undefine, &Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	int	index = (level == levels[0]) * 1
			+ (level == levels[1]) * 2
			+ (level == levels[2]) * 3
			+ (level == levels[3]) * 4;
	(this->*funcPtr[index])();
}

void	Harl::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special- ketchup burger.\nI really do!" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money.\nYou didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free.\nI've been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void	Harl::undefine(void)
{
	std::cout << "ERROR: undefined level" << std::endl;
}
