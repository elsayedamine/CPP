/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsayed <aelsayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 03:46:49 by aelsayed          #+#    #+#             */
/*   Updated: 2025/08/19 18:26:51 by aelsayed         ###   ########.fr       */
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

};

std::ostream& operator<<(std::ostream& os, const Fixed& obj);


#endif