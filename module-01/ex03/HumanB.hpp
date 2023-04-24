/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisse <jisse@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 16:01:32 by jisse             #+#    #+#             */
/*   Updated: 2023/04/20 17:45:20 by jisse            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP
# include <iostream>
# include "Weapon.hpp"

class HumanB
{
	public: 
		HumanB(std::string name);

		void	setWeapon(Weapon weapon);
		void	attack( void );
	private:
		std::string _name;
		std::string	*_weapon;
};
#endif 