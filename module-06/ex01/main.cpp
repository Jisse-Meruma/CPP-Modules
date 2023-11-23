#include "Serializer.hpp"

int	main()
{	
	Data		*structure;
	Data		*copy;
	uintptr_t 	ptr;


	structure = new Data;

	structure->charactar = 'A';
	structure->numb = 42;
	structure->pointy_number = 42.42;

	ptr = Serializer::serialize(structure);
	copy = Serializer::deserialize(ptr);

	if (copy == structure)
	{
		std::cout << "Yay Everything went according to plan!" << std::endl;
		std::cout << copy->charactar << std::endl;
		std::cout << copy->numb << std::endl;
		std::cout << copy->pointy_number << std::endl;
	}
	else
		std::cout << "HMMMM something went wrong better to check out what went wrong :((" << std::endl;
	delete structure;
	return (0);
}