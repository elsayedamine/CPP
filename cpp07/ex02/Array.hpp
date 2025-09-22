/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsayed <aelsayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 03:15:41 by aelsayed          #+#    #+#             */
/*   Updated: 2025/09/22 03:47:19 by aelsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <stdexcept>

template <typename T>
class Array
{
	private:
		T				*_data;
		unsigned int	_size;
	public:
		Array();
		Array(unsigned int len);
		Array(const Array &other);
		Array &operator=(const Array &other);
		~Array();

		unsigned int	size(void) const;

		T&				operator[](unsigned int idx);
		const T&		operator[](unsigned int idx) const;
};

#include "Array.tpp"

#endif