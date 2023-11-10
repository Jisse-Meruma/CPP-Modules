#include "ScalarConverte.hpp"

int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout << "Please Give 1 Argument to the program" << std::endl;
		return (1);
	}

	std::string input(argv[1]);

	ScalarConverte::convert(input);
	return (0);
}