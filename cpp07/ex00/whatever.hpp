/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsayed <aelsayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 02:37:13 by aelsayed          #+#    #+#             */
/*   Updated: 2025/09/22 02:37:47 by aelsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>

template<typename T>
void	swap(T &a, T &b)
{
	T tmp = a;
	a = b;
	b = tmp;
}

template<typename T>
T	min(const T &a, const T &b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

template<typename T>
T	max(const T &a, const T &b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

#endif