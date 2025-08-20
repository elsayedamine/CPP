/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsayed <aelsayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 16:25:22 by aelsayed          #+#    #+#             */
/*   Updated: 2025/08/19 18:26:44 by aelsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
// Copy constructor = used when creating a new object from another.
// Copy assignment operator = used when overwriting an existing object.

Fixed::Fixed() : value(0)
{

}
Fixed::Fixed(const Fixed &other)
{
	this->value = other.value;
}
Fixed::Fixed(const int number)
{
	this->value = number << this->fractionalBits;
}
Fixed::Fixed(const float number)
{
	this->value = roundf(number * (1 << this->fractionalBits));
}
Fixed::~Fixed()
{

}

Fixed	&Fixed::operator=(const Fixed &other)
{
	if (this != &other)
	this->value = other.getRawBits();
	return (*this);
}
float	Fixed::toFloat(void) const
{
	return ((this->value / (float)(1 << this->fractionalBits)));
}
int	Fixed::toInt(void) const
{
	return (this->value >> this->fractionalBits);
}
int Fixed::getRawBits(void) const
{
	return (this->value);
}
void Fixed::setRawBits(int const raw)
{
	this->value = raw;
}

std::ostream	&operator<<(std::ostream& os, const Fixed& obj)
{
    os << obj.toFloat();
    return os;
}
