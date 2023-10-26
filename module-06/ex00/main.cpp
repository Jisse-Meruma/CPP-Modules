#include "ScalarConverte.hpp"

int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout << "Please Give 1 Argument to the program" << std::endl;
	}

	std::string input(argv[1]);

	ScalarConverte::convert(input);
}