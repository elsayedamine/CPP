/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsayed <aelsayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 15:37:49 by aelsayed          #+#    #+#             */
/*   Updated: 2025/09/01 17:00:05 by aelsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : stored(0)
{
	for (int i = 0; i < 4; i++)
		memory[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
	*this = other;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
	if (this != &other)
	{
		stored = other.stored;
		for (int i = 0; i < 4; i++)
		{
			if (memory[i])
				delete memory[i];
			if (other.memory[i])
				memory[i] = other.memory[i]->clone();
			else
				memory[i] = NULL;
		}
	}
	return (*this);
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if (memory[i])
		{
			delete memory[i];
            memory[i] = NULL;
		}
	}

}

void    MateriaSource::learnMateria(AMateria* m)
{
	if (stored < 4 && m)
		memory[stored++] = m->clone();
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < stored; i++)
		if (memory[i] && memory[i]->getType() == type)
			return memory[i]->clone();
	return NULL;
}