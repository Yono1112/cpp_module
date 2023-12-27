#include "Harl.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "ERROR: Invalid argument" << std::endl;
		return (1);
	}
	Harl	harl = Harl();

	harl.filterLevel(argv[1]);
	return (0);
}
