#include <iostream>

int	main(int argc, char *argv[]) {

	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 0;
	}

	for (int index = 1; index < argc; index++){
		for (size_t i = 0; i < std::strlen(argv[index]); i++){
			argv[index][i] = std::toupper(argv[index][i]);
		}
		std::cout << argv[index];
	}
	std::cout << std::endl;
	return 0;
}