/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsayed <aelsayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 18:12:00 by aelsayed          #+#    #+#             */
/*   Updated: 2025/09/22 19:36:35 by aelsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>
#include <iterator>
#include <stdexcept>
#include <limits.h>
#include <algorithm>
class Span
{
	private:
		unsigned int	max_size;
		std::vector<int> arr;
		int				min;
		int				max;
	public:
		Span();
		Span(unsigned int n);
		Span(const Span & other);
		Span&	operator=(const Span & other);
		~Span();

		void	addNumber(int num);
		int		longestSpan() const;
		int		shortestSpan() const;

		template <typename It>
		void addNumbers(It begin, It end)
		{
			size_t available = max_size - arr.size();
			size_t incoming  = std::distance(begin, end);

			if (incoming <= available)
				arr.insert(arr.end(), begin, end);
			else
			{
				It cut = begin;
				std::advance(cut, available);
				arr.insert(arr.end(), begin, cut);
				throw std::overflow_error("Span overflow: not all numbers were inserted");
			}
		}
};


#endif