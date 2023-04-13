#include "PhoneBook.hpp"
#include <iostream>

int main(void)
{
	size_t index;
	size_t counter;
	PhoneBook phone_book;
	std::string cmd;

	index = 0;
	counter = 0;
	while (true) {
	
		std::cout << "Input (ADD), (SEARCH), (EXIT) $: ";
		std::cin >> cmd;
		std::cout << "You entered " << cmd << std::endl;

		if (!cmd.compare("EXIT"))
			break;

		else if (!cmd.compare("ADD"))
		{
			if (index == 8)
				index = 0;
			phone_book.task_add(index);
			std::cout << "Added Contact at index " << index << std::endl;
			index += 1;
			counter += 1;
		}

		else if (!cmd.compare("SEARCH"))
		{
			if (counter < 8)
				phone_book.task_search(counter);
			else
				phone_book.task_search(8);
		}
	}
}