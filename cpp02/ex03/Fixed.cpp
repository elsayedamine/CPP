/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsayed <aelsayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 16:25:22 by aelsayed          #+#    #+#             */
/*   Updated: 2025/08/23 13:58:22 by aelsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
// Copy constructor = used when creating a new object from another.
/*------------Constructions------------*/
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

/*------------Members------------*/
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

std::ostream	&operator<<(std::ostream& outputStreamer, const Fixed& obj)
{
	outputStreamer << obj.toFloat();
	return outputStreamer;
}

/*------------Operators------------*/
// Comparison operators
bool 	Fixed::operator>(const Fixed& other) const
{
	return (this->value > other.value);
}
bool 	Fixed::operator<(const Fixed& other) const
{
	return (this->value < other.value);
}
bool 	Fixed::operator>=(const Fixed& other) const
{
	return (this->value >= other.value);
}
bool 	Fixed::operator<=(const Fixed& other) const
{
	return (this->value <= other.value);
}
bool 	Fixed::operator==(const Fixed& other) const
{
	return (this->value == other.value);
}
bool 	Fixed::operator!=(const Fixed& other) const
{
	return (this->value != other.value);
}

// 	Arithmetic operators
Fixed 	Fixed::operator+(const Fixed& other) const
{
	Fixed result;
	result.setRawBits(this->value + other.value);
	return (result);
}
Fixed 	Fixed::operator-(const Fixed& other) const
{
	Fixed result;
	result.setRawBits(this->value - other.value);
	return (result);
}
Fixed	Fixed::operator*(const Fixed& other) const
{
	return Fixed((this->value * other.value) >> fractionalBits);
}
Fixed	Fixed::operator/(const Fixed& other) const
{
	return Fixed((this->value << fractionalBits) / other.value);
}

// 	Increment / Decrement operators
Fixed	&Fixed::operator++()
{
	this->value++;
	return (*this);
}
Fixed	Fixed::operator++(int)
{
	Fixed	old(*this);
	this->value++;
	return (old);
}
Fixed	&Fixed::operator--()
{
	this->value--;
	return (*this);
}
Fixed	Fixed::operator--(int)
{
	Fixed	old(*this);
	this->value--;
	return (old);
}

//  Min / Max
Fixed		&Fixed::min(Fixed &a, Fixed &b)
{
	return (a < b ? a : b);
}
const Fixed	&Fixed::min(const Fixed &a, const Fixed &b)
{
	return (a < b ? a : b);
}
Fixed		&Fixed::max(Fixed &a, Fixed &b)
{
	return (a > b ? a : b);
}
const Fixed	&Fixed::max(const Fixed &a, const Fixed &b)
{
	return (a > b ? a : b);
}
