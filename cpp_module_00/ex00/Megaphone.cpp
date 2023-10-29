#include <iostream>

char	ft_toupper(char c)
{
	if ('a' <= c && c <= 'z')
		c -= 32;
	return (c);
}

int	main(int argc, char **argv) {
	if (argc < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for(int i = 1; i < argc; i++) {
			for(size_t j = 0; j < std::strlen(argv[i]); j++) {
				std::cout << ft_toupper(argv[i][j]);
			}
		}
		std::cout << std::endl;
	}
	return (0);
}
