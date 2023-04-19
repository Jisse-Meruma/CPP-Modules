/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeruma <jmeruma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 15:58:57 by jmeruma           #+#    #+#             */
/*   Updated: 2023/04/19 10:19:31 by jmeruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Zombie 
{
	
	public:
		void announce( void );

		Zombie ( std::string name );
		~Zombie ( void );
	
	private:
		std::string _name;
};

void	randomChump( std::string name );
Zombie*	newZombie( std::string name );
