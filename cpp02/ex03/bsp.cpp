/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsayed <aelsayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 18:32:41 by aelsayed          #+#    #+#             */
/*   Updated: 2025/08/20 12:01:41 by aelsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point sub(const Point &v1, const Point &v2)
{
	Fixed newX = v1.getX() - v2.getX();
	Fixed newY = v1.getY() - v2.getY();
	return Point(newX, newY);
}

Fixed	cross(const Point &a, const Point &b)
{
	return (a.getX() * b.getY() - a.getY() * b.getX());
}

Fixed abs(const Fixed &f)
{
	return (f < Fixed(0) ? f * -1 : f);
}

bool	bsp(Point const a, Point const b, Point const c, Point const p)
{
	if (p == a || p == b || p == c || a == b || a == c || b == c)
		return (false);

	Fixed area_ABC = cross(sub(b, a), sub(c, a));
	Fixed area_ABP = cross(sub(b, a), sub(p, a));
	Fixed area_BCP = cross(sub(c, b), sub(p, b));
	Fixed area_CAP = cross(sub(a, c), sub(p, c));


	if (area_ABC > Fixed(0))
		return (area_ABP > Fixed(0) && area_CAP > Fixed(0) && area_BCP > Fixed(0));
	else
		return (area_ABP < Fixed(0) && area_CAP < Fixed(0) && area_BCP < Fixed(0));
}
