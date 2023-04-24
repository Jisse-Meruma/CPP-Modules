/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeruma <jmeruma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 14:10:31 by jmeruma           #+#    #+#             */
/*   Updated: 2023/04/21 15:07:30 by jmeruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void	Harl::complain( std::string level )
{
	Harl obj;
	bool check = false;
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	t_func toxic[4] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	
	for (size_t i = 0; i < 4; i++)
	{
		if (level == levels[i])
			check = true;
	}

	if (!check)
	{
		std::cout << "Wrong level has been given please! harl is unstoppable" << std::endl;
		std::exit(EXIT_FAILURE);
	}

	for (size_t i = 0; i < 4; i++)
	{
		if (level == levels[i])
		{
			(obj.*toxic[i])();
			break;
		}
		(obj.*toxic[i])();
		std::cout << std::endl;
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
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::error( void )
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}
