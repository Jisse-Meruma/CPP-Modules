/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisse <jisse@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 16:01:39 by jisse             #+#    #+#             */
/*   Updated: 2023/04/20 17:45:46 by jisse            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon weapon) 
{
	this->_name = name;
	this->_weapon = weapon.getType();
	
}

void	HumanA::attack( void )
{
	std::cout << this->_name << " attacks with their " << this->_weapon << std::endl;
}