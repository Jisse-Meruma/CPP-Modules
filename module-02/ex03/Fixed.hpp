/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeruma <jmeruma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 17:11:13 by jmeruma           #+#    #+#             */
/*   Updated: 2023/05/12 17:01:11 by jmeruma          ###   ########.fr       */
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

	int		toInt( void ) const;
	int		getFixed_point( void ) const;
	int		getFractional_bit( void ) const;
	float	toFloat( void ) const;

	static Fixed	&max( Fixed &C1, Fixed &C2);
	static Fixed	&min( Fixed &C1, Fixed &C2);
	
	static const Fixed &max( const Fixed &C1, const Fixed &C2);
	static const Fixed &min( const Fixed &C1, const Fixed &C2);
	
	Fixed	&operator=( const Fixed &fixed );
	bool	operator<( const Fixed &C1 ) const;
	bool	operator>( const Fixed &C1 ) const;
	bool	operator>=( const Fixed &C1 );
	bool	operator<=( const Fixed &C1 );
	bool	operator==( const Fixed &C1 );
	bool	operator!=( const Fixed &C1 );

	Fixed	operator+( const Fixed &C1 );
	Fixed	operator-( const Fixed &C1 );
	Fixed	operator*( const Fixed &C1 );
	Fixed	operator/( const Fixed &C1 );

	Fixed	&operator++( void );
	Fixed	&operator--( void );
	Fixed	operator++(int);
	Fixed	operator--(int);

	private:
		int					_fixed_point;
		static const int	_fractional_bit = 8;
};

std::ostream		&operator<<(std::ostream &out, const Fixed &C);



