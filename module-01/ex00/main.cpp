/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeruma <jmeruma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 16:19:01 by jmeruma           #+#    #+#             */
/*   Updated: 2023/05/24 13:45:15 by jmeruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	std::cout << "This is a heap allocated class!" << std::endl << std::endl;
	Zombie *jisse = newZombie("Jisse");
	Zombie *test1 = newZombie("test1");
	Zombie *test2 = newZombie("test2");

	jisse->announce();
	test1->announce();
	test2->announce();
	
	std::cout << "This is a stack created class!" << std::endl;
	randomChump("Ruben");
	randomChump("Richard");
	randomChump("Cheese");
	randomChump("Dante");

	std::cout << "Free the allocated object Zombie!" << std::endl;
	delete jisse;
	delete test1;
	delete test2;

	system("leaks -q zombie");
}
