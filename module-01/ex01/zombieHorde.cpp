/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisse <jisse@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 10:24:11 by jmeruma           #+#    #+#             */
/*   Updated: 2023/04/20 14:57:15 by jisse            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombieHorde( int N, std::string name)
{
	Zombie *horde = new Zombie[N];

	for (int i = 0; i < N; i++) {
		horde[i] = Zombie(name);
	}

	return (horde);
}