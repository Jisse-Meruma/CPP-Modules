/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisse <jisse@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 15:58:57 by jmeruma           #+#    #+#             */
/*   Updated: 2023/04/20 15:00:47 by jisse            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Zombie 
{
	
	public:
		void announce( void );

		Zombie ( std::string name );
		Zombie ( void );
		~Zombie ( void );
	
	private:
		std::string _name;
};

Zombie*	zombieHorde( int N, std::string name);

