/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsayed <aelsayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 02:48:59 by aelsayed          #+#    #+#             */
/*   Updated: 2025/09/22 02:58:12 by aelsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP 
# define ITER_HPP 

# include <iostream>

template <typename T>
void	iter(T *array, size_t len, void (*f)(T &))
{
	if (!f || !array)
		return ;
	for (size_t i = 0; i < len; i++)
		f(array[i]);
}

// print function
template <typename T>
void printElement(T &x)
{
	std::cout << x << " ";
}

// modify function
template <typename T>
void	incrementElement(T &x)
{
	x += 1;
}


#endif