#include <iostream>
#include "RPN.hpp"

int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout << "Too many or Too little arguments please provide only 1" << std::endl;
		return (EXIT_FAILURE);
	}

	try
	{
		std::cout << rpn(argv[1]) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}