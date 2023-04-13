#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>

#define WIDTH 10

void	PhoneBook::task_add(size_t i){
	Contact 	contact;
	std::string value;

	std::cout << "First Name: ";
	std::cin >> value;
	contact.setFirstname(value);

	std::cout << "Last Name: ";
	std::cin >> value;
	contact.setLastname(value);

	std::cout << "Nick Name: ";
	std::cin >> value;
	contact.setNickname(value);

	std::cout << "Phone Number: ";
	std::cin >> value;
	contact.setPhonenumber(value);

	std::cout << "Darkest Secret o-o: ";
	std::cin >> value;
	contact.setSecrect(value);

	info[i] = contact;
}

void	PhoneBook::print_contact(std::string data, std::string end){
	size_t length;

	length = data.length();
	if (length <= WIDTH)
	{
		std::cout << std::setw(WIDTH) << data << end;
	}
	else
	{
		std::cout << std::setw(WIDTH - 1) << data.substr(0, 9) << "." << end;
	}
}

void  	PhoneBook::task_search(int length){
	std::cout << std::endl;
	for (int i = 0; i < length; i++)
	{
		std::cout << std::setw(WIDTH) << i + 1 << "|";
		print_contact(info[i].getFirstname(), "|");
		print_contact(info[i].getLastname(), "|");
		print_contact(info[i].getNickname(), "|");
		print_contact(info[i].getPhonenumber(), "|");
		print_contact(info[i].getSecrect(), "\n");
	}
	std::cout << std::endl;
}