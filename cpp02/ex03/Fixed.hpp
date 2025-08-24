/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsayed <aelsayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 03:46:49 by aelsayed          #+#    #+#             */
/*   Updated: 2025/08/24 17:33:33 by aelsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
	private:
		int					value;
		static const int	fractionalBits = 8;

	public:
		/*------------Constructions------------*/
		Fixed();
		Fixed(const Fixed& other);
		Fixed(const int number);
		Fixed(const float number);
		~Fixed();

		/*------------Members------------*/
		Fixed	&operator=(const Fixed& other);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;

		/*------------Operators------------*/
		// Comparison operators
		bool 	operator>(const Fixed& other) const;
		bool 	operator<(const Fixed& other) const;
		bool 	operator>=(const Fixed& other) const;
		bool 	operator<=(const Fixed& other) const;
		bool 	operator==(const Fixed& other) const;
		bool 	operator!=(const Fixed& other) const;
		
		// 	Arithmetic operators
		Fixed 	operator+(const Fixed& other) const;
		Fixed 	operator-(const Fixed& other) const;
		Fixed 	operator*(const Fixed& other) const;
		Fixed 	operator/(const Fixed& other) const;
		
		// 	Increment / Decrement operators
		Fixed	&operator++();    // pre-increment
		Fixed 	operator++(int);  // post-increment
		Fixed	&operator--();    // pre-decrement
		Fixed	operator--(int);  // post-decrement

		//  Min / Max
		static Fixed		&min(Fixed &a, Fixed &b);
		static const Fixed	&min(const Fixed &a, const Fixed &b);
		static Fixed		&max(Fixed &a, Fixed &b);
		static const Fixed	&max(const Fixed &a, const Fixed &b);
	};
	
std::ostream& operator<<(std::ostream& os, const Fixed& obj);

#endif