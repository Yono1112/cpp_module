#include <iostream>
#include <fstream>
#include <string>

std::string	replace_str(std::string input_line, std::string before_str, std::string after_str)
{
	size_t		i;
	std::string	replaced_str;

	i = 0;
	if (before_str == "")
		return (input_line);
	while (i < input_line.length())
	{
		if (input_line.substr(i, before_str.length()) == before_str)
		{
			replaced_str += after_str;
			i += before_str.length();
		}
		else
		{
			replaced_str += input_line[i];
			i++;
		}
	}
	return (replaced_str);
}

int	main(int argc, char **argv)
{
	std::string		filename;
	std::string		input_line;
	std::string		current_line;
	std::string		s1;
	std::string		s2;

	if (argc != 4)
	{
		std::cerr << "invalid argument" << std::endl;
		return (1);
	}
	filename = argv[1];
	s1 = argv[2];
	s2 = argv[3];
	std::ifstream	ifs(filename.c_str());
	if (ifs.fail())
	{
		std::cerr << "cannnot open file" << std::endl;
		return (1);
	}
	std::ofstream	ofs(filename.append(".replace").c_str());
	if (getline(ifs, input_line))
	{
		current_line = input_line;
		while (getline(ifs, input_line))
		{
			// std::cout << "current_line '" << current_line << "'" << std::endl;
			ofs << replace_str(current_line, s1, s2) << std::endl;
			current_line = input_line;
		}
		// std::cout << "current_line '" << current_line << "'" << std::endl;
		ofs << replace_str(current_line, s1, s2);
	}
	return (0);
}
