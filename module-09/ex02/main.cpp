#include "PmergeMe.hpp"

void error_message(void)
{
    std::cout << "Error" << std::endl;
}

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		error_message();
		return (EXIT_FAILURE);
	}

	try
	{
		PmergeMe mergeme(argv + 1);

		mergeme.sort();

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}