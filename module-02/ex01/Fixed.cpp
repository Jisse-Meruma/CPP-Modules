/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeruma <jmeruma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 17:16:50 by jmeruma           #+#    #+#             */
/*   Updated: 2023/05/02 17:57:28 by jmeruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed( const Fixed &fixed )
{
	std::cout << "Copy constructor called" << std::endl;
	this->_fixed_point = fixed._fixed_point;
}

Fixed::Fixed( void )
{
	std::cout << "Default constructor called" << std::endl;
	this->_fixed_point = 0;
}

Fixed::Fixed( const int interger)
{
	std::cout << "Int constructor called" << std::endl;
	this->_fixed_point = interger << this->_fractional_bit;
}

Fixed::Fixed( const float floating_point)
{
	std::cout << "Float constructor called" << std::endl;
	this->_fixed_point = roundf(floating_point * (2 << (this->_fractional_bit - 1)));
}

Fixed::~Fixed( void )
{
	std::cout << "Destructor called" << std::endl;
}

void	Fixed::operator=(const Fixed &C)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_fixed_point = C._fixed_point;
}


int	Fixed::toInt( void ) const
{
	return (this->_fixed_point >> this->_fractional_bit); 
}

float	Fixed::toFloat( void ) const
{
	return (roundf(this->_fixed_point / (2 << (this->_fractional_bit - 1))));
}

int	Fixed::getFixed_point( void ) const
{
	return (this->_fixed_point);
}

int Fixed::getFractional_bit( void ) const
{
	return (this->_fractional_bit);
}

std::ostream	&operator<<(std::ostream &os, const Fixed &C) 
{
	os << roundf(C.getFixed_point()) / (2 << (C.getFractional_bit() - 1));
	return os;	
}
