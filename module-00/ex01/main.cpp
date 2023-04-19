/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeruma <jmeruma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 13:24:32 by jmeruma           #+#    #+#             */
/*   Updated: 2023/04/17 15:09:57 by jmeruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#define MAX 8
#define EXIT_FAILURE 1

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
		if (!std::getline(std::cin, cmd))
			std::exit(EXIT_FAILURE);
		std::cout << "You entered " << cmd << std::endl;

		if (cmd == "EXIT")
			break;

		else if (cmd == "ADD")
		{
			if (index == MAX)
				index = 0;
			phone_book.task_add(index);
			std::cout << "Added Contact at index " << index + 1 << std::endl;
			index += 1;
			counter += 1;
		}

		else if (cmd == "SEARCH")
		{
			if (counter == 0)
			{
				std::cout << "Error cannot search an empty phonebook! [TRY ADD!]" << std::endl;
				continue;
			}
			if (counter < MAX)
				phone_book.task_search(counter);
			else
				phone_book.task_search(MAX);
		}
	}
}