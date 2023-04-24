/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeruma <jmeruma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 14:00:39 by jmeruma           #+#    #+#             */
/*   Updated: 2023/04/21 14:40:55 by jmeruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Harl
{
	public:

		void complain( std::string level);

	private:
		
		void debug( void );
 		void info( void );
		void warning( void );
 		void error( void );
};

typedef void (Harl::*t_func)(void);