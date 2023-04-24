/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisse <jisse@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 16:01:19 by jmeruma           #+#    #+#             */
/*   Updated: 2023/04/20 15:13:02 by jisse            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
	std::cout << "created Zombie with a name" << std::endl;
	this->_name = name;
}

Zombie::Zombie( void )
{
	std::cout << "created Zombie" << std::endl;	
}

Zombie::~Zombie( void )
{
	std::cout << this->_name << ": Destroyed!" << std::endl;
}

void	Zombie::announce( void )
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
