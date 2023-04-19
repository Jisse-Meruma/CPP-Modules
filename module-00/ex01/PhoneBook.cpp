/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeruma <jmeruma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 13:24:34 by jmeruma           #+#    #+#             */
/*   Updated: 2023/04/17 15:12:58 by jmeruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>

#define WIDTH 10
#define INVALID 10
#define WITHESPACE "\t\v\n\f\r "

std::string	PhoneBook::setvalue(std::string message)
{
	std::string value;

	while (true)
	{
		std::cout << message;
		if (!std::getline(std::cin, value))
			std::exit(EXIT_FAILURE);
		if (value.find_first_not_of(WITHESPACE) != std::string::npos)
			break ;
		std::cout << "Invalid Input please try again [NO WHITESPACES!]" << std::endl;
	}
	return (value);
}

void	PhoneBook::task_add(size_t i){
	Contact 	contact;
	std::string value;

	contact.setFirstname(setvalue("First Name: "));
	contact.setLastname(setvalue("Last Name: "));
	contact.setNickname(setvalue("Nick Name: "));
	contact.setPhonenumber(setvalue("Phone Number: "));
	contact.setSecrect(setvalue("Darkest Secret o-o: "));

	_info[i] = contact;
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
	std::string index;
	int			index_int;
	
	std::cout << "+----------+----------+----------+----------+" << std::endl;
	std::cout << "|     index|first name| last name| nick name|" << std::endl;
	std::cout << "+----------+----------+----------+----------+" << std::endl;
	std::cout << std::endl;

	for (int i = 0; i < length; i++)
	{
		std::cout << std::setw(WIDTH) << i + 1 << "|";
		print_contact(_info[i].getFirstname(), "|");
		print_contact(_info[i].getLastname(), "|");
		print_contact(_info[i].getNickname(), "\n");
	}

	std::cout << std::endl;
	std::cout << "Please select a index to Search!" << std::endl;
	if (!std::getline(std::cin, index))
			std::exit(EXIT_FAILURE);

	if (index[0] < '9' && index[0] > '0' && index[1] == '\0')
		index_int = index[0] - '0';
	else
		index_int = INVALID;
	if (index_int <= length && index_int <= 8)
	{
		std::cout << std::endl;
		std::cout << "First name: " << _info[index_int - 1].getFirstname() << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "Last name: " << _info[index_int - 1].getLastname() << std::endl; 
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "Nick name: " << _info[index_int - 1].getNickname() << std::endl; 
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "Phone Number: " << _info[index_int - 1].getPhonenumber() << std::endl; 
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "Darkest evil secret: " << _info[index_int - 1].getSecrect() << std::endl; 
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << std::endl;
	}
	else
		std::cout << "Invalid Index has been given" << std::endl;
}