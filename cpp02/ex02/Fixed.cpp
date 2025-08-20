/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsayed <aelsayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 16:25:22 by aelsayed          #+#    #+#             */
/*   Updated: 2025/08/19 18:26:30 by aelsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
// Copy constructor = used when creating a new object from another.
// Copy assignment operator = used when overwriting an existing object.
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

std::ostream	&operator<<(std::ostream& os, const Fixed& obj)
{
    os << obj.toFloat();
    return os;
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
	return (Fixed(this->value + other.value));
}
Fixed 	Fixed::operator-(const Fixed& other) const
{
	return (Fixed(this->value - other.value));
}
Fixed	Fixed::operator*(const Fixed& other) const
{
	return (Fixed(this->toFloat() * other.toFloat()));
}
Fixed	Fixed::operator/(const Fixed& other) const
{
	if (other.getRawBits() == 0)
		return (Fixed(0));
	return (Fixed(this->toFloat() / other.toFloat()));
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
