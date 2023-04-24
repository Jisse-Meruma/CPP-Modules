/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisse <jisse@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 16:01:34 by jisse             #+#    #+#             */
/*   Updated: 2023/04/20 17:46:38 by jisse            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	this->_name = name;
}

void	HumanB::setWeapon( Weapon weapon)
{
	this->_weapon = &(weapon.getType());
}

void	HumanB::attack( void )
{
	std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
}