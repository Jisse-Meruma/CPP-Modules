/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeruma <jmeruma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 16:19:01 by jmeruma           #+#    #+#             */
/*   Updated: 2023/05/24 13:47:39 by jmeruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	int amount = 10;
	Zombie *horde;

	horde = zombieHorde(amount, "Jack");

	for (int i = 0; i < amount; i++)
		horde[i].announce();

	std::cout << "Free the allocated object Zombie!" << std::endl;

	// see if you find how to properly free the ZombieHorde : D
	delete[] horde;

	system("leaks zombiehorde");
}
