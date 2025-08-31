/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsayed <aelsayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 18:17:53 by aelsayed          #+#    #+#             */
/*   Updated: 2025/08/30 00:36:25 by aelsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain Def Constr" << std::endl;
}

Brain::Brain(const Brain& other)
{
	*this = other;
	std::cout << "Brain Copy Constr" << std::endl;
}

Brain& Brain::operator=(const Brain& other)
{
	int i = -1;
	if (this != &other)
		while (++i < 100)
			ideas[i] = other.ideas[i];
	return *this;
}

Brain::~Brain()
{
	std::cout << "Brain Destr" << std::endl;
}

str Brain::getIdea(int index) const
{
	if (index < 0 || index >= 100)
		return "";
	return ideas[index];
}

void Brain::setIdea(int index, const str& idea)
{
	if (index < 0 || index >= 100)
		return;
	ideas[index] = idea;
}
