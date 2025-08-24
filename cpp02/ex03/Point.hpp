/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsayed <aelsayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 18:32:46 by aelsayed          #+#    #+#             */
/*   Updated: 2025/08/24 14:36:22 by aelsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef POINT_H
# define POINT_H

# include "Fixed.hpp"

class Point
{
	private:
		const Fixed	x;
		const Fixed	y;

	public:
		Point();
		~Point();
		Point(const float x, const float y);
		Point(const Point& other);
		Point(const Fixed &fx, const Fixed &fy);
		Point& operator=(const Point& other);
		Fixed getX() const;
		Fixed getY() const;
		bool 	operator==(const Point& other) const;

};

#endif