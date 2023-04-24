/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeruma <jmeruma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 15:03:14 by jmeruma           #+#    #+#             */
/*   Updated: 2023/04/24 11:53:41 by jmeruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char *argv[])
{
	Harl hello;

	if (argc != 2)
	{
		std::cout << "Harl is complaining sooo much that the program cannot handle it please only try [1] complaint!" << std::endl;
		return (-1);
	}

	std::string level(argv[1]);

	std::cout << "Harl just lost a brain cell" << std::endl;
	hello.complain(level);

	return 0;
}