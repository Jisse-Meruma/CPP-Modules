/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeruma <jmeruma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 14:10:31 by jmeruma           #+#    #+#             */
/*   Updated: 2023/05/01 16:05:46 by jmeruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void	Harl::complain( std::string level )
{
	bool check = false;	
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (size_t i = 0; i < 4; i++)
	{
		if (level == levels[i])
			check = true;
	}

	if (!check)
	{
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		return ;
	}

	switch (level[0]) {
		case 'D':
			std::cout << "[ DEBUG ]" << std::endl;
			debug();
		case 'I':
			std::cout << "[ INFO ]" << std::endl;
			info();
		case 'W':
			std::cout << "[ WARNING ]" << std::endl;
			warning();
		case 'E':
			std::cout << "[ ERROR ]" << std::endl;
			error();
			break;
	}
}

void	Harl::debug( void )
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void	Harl::info( void )
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void	Harl::warning( void )
{
	std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::error( void )
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}
