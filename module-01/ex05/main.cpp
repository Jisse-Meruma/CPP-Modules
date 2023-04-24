/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeruma <jmeruma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 15:03:14 by jmeruma           #+#    #+#             */
/*   Updated: 2023/04/21 15:06:57 by jmeruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(void)
{
	Harl hello;

	std::cout << "Harl just lost a brain cell" << std::endl;
	hello.complain("ERROR");

	std::cout << "HARL INFO" << std::endl;
	hello.complain("INFO");

	std::cout << "HARL ON A WHOLE OTHER LEVEL" << std::endl;
	hello.complain("a");
}