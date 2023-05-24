/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeruma <jmeruma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 12:06:20 by jmeruma           #+#    #+#             */
/*   Updated: 2023/05/24 15:27:58 by jmeruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#define ERROR -1


int	main(int argc, char *argv[])
{
	if (argc != 4)
	{
		std::cout << "Error can only accept [3] arguments" << std::endl;
		return (ERROR);
	}

	std::string file(argv[1]); // Transform a char * into an object string;
	std::ifstream infile(file);

	if (!infile.is_open()) // Can the infile be opened if not send error
	{
		std::cout << "Unable to open file!" << std::endl;
		return (ERROR);
	}

	std::ofstream outfile(file.append(".replace")); // Create 2 filestreams infile and outfile with the .replace
	std::string find_word(argv[2]);
	std::string replace_word(argv[3]);
	std::string line;

	while (std::getline(infile, line)) // Get a line from the file specified, and put it in line
	{
		size_t position = line.find(find_word); // Find the word specified in the argument return a position index to that word! ~ if it cannot find the word it will go to npos(NULL terminator) 
		while (position != line.npos)
		{
			line = line.substr(0, position) + replace_word + line.substr(position + find_word.length()); // substring the beginning till the occurence, then add the new word, then skip the old word and copy everything till npos
			position = line.find(find_word, position + replace_word.length()); // find the next word in the string and do the same thing again! 
		}
		outfile << line;
		if (infile.eof())
			break ;
		outfile << std::endl; // Write the line to the outfile
	}

	infile.close(); // And ofc close every filestream after done using it
	outfile.close();
	return (0);

}