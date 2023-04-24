/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeruma <jmeruma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 12:06:20 by jmeruma           #+#    #+#             */
/*   Updated: 2023/04/21 12:29:12 by jmeruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>


int	main(int argc, char *argv[])
{
	if (argc != 4)
	{
		std::cout << "Error can only accept [3] arguments" << std::endl;
		return (1);
	}
	

	std::string file(argv[1]);
	std::ifstream file_read(file);
	std::ofstream file_write(file.append(".replace"));
	if (file.is_open())
	{
		
	}
	else
		std::cout << "Unable to open file!" << std::endl;
	std::string s1(argv[2]);
	std::string s2(argv[3]);

	file..
}