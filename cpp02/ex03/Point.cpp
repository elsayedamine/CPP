/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsayed <aelsayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 18:32:44 by aelsayed          #+#    #+#             */
/*   Updated: 2025/08/20 11:19:47 by aelsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : x(0), y(0)
{

}

Point::~Point()
{

}

Point::Point(const float a, const float b) : x(Fixed(a)), y(Fixed(b))
{
	
}

Point::Point(const Fixed &fx, const Fixed &fy) : x(fx), y(fy)
{
	
}

Point::Point(const Point& other) : x(other.getX()), y(other.getY())
{

}

Point	&Point::operator=(const Point& other)
{
	(void)other;
	return (*this);
}

Fixed Point::getX() const
{
	return (this->x);
}

Fixed Point::getY() const
{
	return (this->y);
}

bool 	Point::operator==(const Point& other) const
{
	return ((this->getX() == other.getX()) && (this->getY() == other.getY()));
}
