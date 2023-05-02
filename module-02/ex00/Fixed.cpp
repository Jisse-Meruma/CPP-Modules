/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeruma <jmeruma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 17:16:50 by jmeruma           #+#    #+#             */
/*   Updated: 2023/05/02 15:33:30 by jmeruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed( Fixed &fixed )
{
	std::cout << "Copy constructor called" << std::endl;
	this->_fixed_point = (fixed.getRawBits() << this->_fixed_point);
}

Fixed::Fixed( void )
{
	std::cout << "Default constructor called" << std::endl;
	this->_fixed_point = 0;
}

Fixed::~Fixed( void )
{
	std::cout << "Destructor called" << std::endl;
}

void	Fixed::setRawBits( int raw )
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_fixed_point =  raw << this->_fractional_bit;
}

int	Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixed_point >> this->_fractional_bit);
}

void	Fixed::operator=(const Fixed &C)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_fixed_point = C._fixed_point;
}