/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeruma <jmeruma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 17:16:50 by jmeruma           #+#    #+#             */
/*   Updated: 2023/05/15 15:19:43 by jmeruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed( const Fixed &fixed )
{
	this->_fixed_point = fixed._fixed_point;
}

Fixed::Fixed( void )
{
	this->_fixed_point = 0;
}

Fixed::Fixed( const int integer)
{
	this->_fixed_point = integer << this->_fractional_bit;
}

Fixed::Fixed( const float floating_point)
{
	this->_fixed_point = roundf(floating_point * (2 << (this->_fractional_bit - 1)));
}

Fixed::~Fixed( void )
{
}

Fixed	&Fixed::operator=(const Fixed &C)
{
	this->_fixed_point = C._fixed_point;
	return (*this);
}


int	Fixed::toInt( void ) const
{
	return (this->_fixed_point >> this->_fractional_bit); 
}

float	Fixed::toFloat( void ) const
{
	return ((float)this->_fixed_point) / (2 << (this->_fractional_bit - 1));
}

int	Fixed::getFixed_point( void ) const
{
	return (this->_fixed_point);
}

int Fixed::getFractional_bit( void ) const
{
	return (this->_fractional_bit);
}

std::ostream	&operator<<(std::ostream &out, const Fixed &C)
{
	out << C.toFloat();
	return (out);
}

bool	Fixed::operator<(const Fixed &C) const
{
	if (this->getFixed_point() < C.getFixed_point())
		return (true);
	return (false);
}

bool	Fixed::operator>(const Fixed &C) const
{
	if (this->getFixed_point() > C.getFixed_point())
		return (true);
	return (false);
}

bool	Fixed::operator>=(const Fixed &C)
{
	if (this->getFixed_point() >= C.getFixed_point())
		return (true);
	return (false);
}

bool	Fixed::operator<=(const Fixed &C)
{
	if (this->getFixed_point() >= C.getFixed_point())
		return (true);
	return (false);
}

bool	Fixed::operator==(const Fixed &C)
{
	if (this->getFixed_point() == C.getFixed_point())
		return (true);
	return (false);
}

bool	Fixed::operator!=(const Fixed &C)
{
	if (this->getFixed_point() != C.getFixed_point())
		return (true);
	return (false);
}

Fixed	Fixed::operator+(const Fixed &C)
{
	Fixed temp(this->toFloat() + C.toFloat());

	return (temp);
}

Fixed	Fixed::operator-(const Fixed &C) const
{
	Fixed temp(this->toFloat() - C.toFloat());

	return (temp);
}

Fixed	Fixed::operator*(const Fixed &C) const
{
	Fixed temp(this->toFloat() * C.toFloat());

	return (temp);
}

Fixed	Fixed::operator/(const Fixed &C)
{
	Fixed temp(this->toFloat() / C.toFloat());

	return (temp);
}

Fixed	&Fixed::operator++( void )
{
	this->_fixed_point++;
	return (*this);
}

Fixed	&Fixed::operator--( void )
{
	this->_fixed_point--;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed temp = *this;
	this->_fixed_point++;
	return (temp);
}

Fixed	Fixed::operator--(int)
{
	Fixed temp = *this;
	this->_fixed_point--;
	return (temp);
}

Fixed	&Fixed::max(Fixed &C1, Fixed &C2)
{
	if (C1 < C2)
		return (C2);
	else
		return (C1);
}

Fixed	&Fixed::min(Fixed &C1, Fixed &C2)
{
	if (C1 < C2)
		return (C1);
	else
		return (C2);
}

const Fixed	&Fixed::max(const Fixed &C1, const Fixed &C2)
{
	if (C1 < C2)
		return (C2);
	else
		return (C1);
}

const Fixed	&Fixed::min(const Fixed &C1, const Fixed &C2)
{
	if (C1 < C2)
		return (C1);
	else
		return (C2);
}
