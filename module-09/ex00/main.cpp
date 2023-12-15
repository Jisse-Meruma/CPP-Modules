#include <iostream>
#include "BitcoinExchange.hpp"

int	main(int argc, char *argv[])
{
	(void)argv;
	if (argc != 2)
	{
		std::cout << "Too many or Too little arguments please provide only 1" << std::endl;
		return (EXIT_FAILURE);
	}

	try
	{
		BitCoinExchange obj;
		obj.LoadInputFile(argv[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
