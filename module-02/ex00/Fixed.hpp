/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeruma <jmeruma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 17:11:13 by jmeruma           #+#    #+#             */
/*   Updated: 2023/05/02 15:33:06 by jmeruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Fixed
{
	public:
	
	Fixed( void );
	Fixed( Fixed &fixed);
	
	~Fixed( void );
	
	int 	getRawBits( void ) const;
	void	setRawBits( int const raw );

	void	operator=(const Fixed &fixed);

	private:
		int 				_fixed_point;
		static const int	_fractional_bit = 8;
};