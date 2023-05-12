/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeruma <jmeruma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 17:11:13 by jmeruma           #+#    #+#             */
/*   Updated: 2023/05/12 13:56:48 by jmeruma          ###   ########.fr       */
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

	Fixed	&operator=(const Fixed &fixed);
	
	private:
		int64_t					_fixed_point;
		static const int	_fractional_bit = 8;
};

std::ostream	&operator<<(std::ostream &os, const Fixed &C);