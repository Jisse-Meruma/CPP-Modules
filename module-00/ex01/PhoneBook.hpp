/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeruma <jmeruma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 13:24:36 by jmeruma           #+#    #+#             */
/*   Updated: 2023/04/17 14:50:20 by jmeruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#define SIZE 8

class PhoneBook {
	public:
		// Contact getContact(size_t i);
		// void	setContact(Contact contact);
		void	task_add(size_t i);
		void	task_search(int lenght);
		void	print_contact(std::string data, std::string end);
		std::string	setvalue(std::string message);

	private:
		Contact _info[SIZE];
};