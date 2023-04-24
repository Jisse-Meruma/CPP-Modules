/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisse <jisse@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 16:01:16 by jisse             #+#    #+#             */
/*   Updated: 2023/04/20 17:05:04 by jisse            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
	this->_type = type;
}

Weapon::Weapon(void)
{

}

void	Weapon::setType(std::string type)
{
	this->_type = type;
}

const std::string&	Weapon::getType( void )
{
	return (this->_type);
}