/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisse <jisse@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 15:26:20 by jisse             #+#    #+#             */
/*   Updated: 2023/04/20 15:44:43 by jisse            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void)
{
	std::string string = "HI THIS IS BRAIN";

	std::string *stringPTR = &string;

	std::string &stringREF = string;

	std::cout << "string	" << &string << std::endl;
	std::cout << "string *	" << &stringPTR << std::endl;
	std::cout << "string &	" << &stringREF << std::endl;
	std::cout << std::endl;
	std::cout << "string	" << string << std::endl;
	std::cout << "string *	" << stringPTR << std::endl;
	std::cout << "string &	" << stringREF << std::endl;
	
	
}