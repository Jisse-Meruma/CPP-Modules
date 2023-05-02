/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeruma <jmeruma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 17:11:13 by jmeruma           #+#    #+#             */
/*   Updated: 2023/05/02 17:02:39 by jmeruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Fixed
{
	public:
	
	Fixed( void );
	Fixed( const Fixed &fixed);
	Fixed( const int interger );
	Fixed( const float floating_point);
	
	~Fixed( void );

	int		getFixed_point( void ) const;
	int		getFractional_bit( void ) const;
	int		toInt( void ) const;
	float	toFloat( void ) const;

	void				operator=(const Fixed &fixed);
	
	private:
		int					_fixed_point;
		static const int	_fractional_bit = 8;
};

std::ostream	&operator<<(std::ostream &os, const Fixed &C);