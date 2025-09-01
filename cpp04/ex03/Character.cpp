/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsayed <aelsayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 15:00:25 by aelsayed          #+#    #+#             */
/*   Updated: 2025/09/01 17:11:08 by aelsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include <iostream>

Character::Character() : name(""), floorcount(0)
{
	for (int i = 0; i < 4; i++)
		inventory[i] = NULL;
	for (int i = 0; i < 1000; i++)
		floor[i] = NULL;
}

Character::Character(str const& name) : name(name), floorcount(0)
{
	for (int i = 0; i < 4; i++)
		inventory[i] = NULL;
}

Character::Character(const Character& other) : name(other.name), floorcount(other.floorcount)
{
	for (int i = 0; i < 4; i++)
		inventory[i] = other.inventory[i] ? other.inventory[i]->clone() : NULL;

	for (int i = 0; i < 1000; i++)
		floor[i] = i < floorcount && other.floor[i] ? other.floor[i]->clone() : NULL;
}

Character& Character::operator=(const Character& other)
{
	if (this != &other)
	{
		name = other.name;
		floorcount = other.floorcount;
		for (int i = 0; i < 4; i++)
		{
			if (inventory[i])
				delete inventory[i];
			if (other.inventory[i])
				inventory[i] = other.inventory[i]->clone();
			else
				inventory[i] = NULL;
		}
		for (int i = 0; i < floorcount; i++)
			if (floor[i])
				delete floor[i];
		for (int i = 0; i < floorcount; i++)
			floor[i] = other.floor[i] ? other.floor[i]->clone() : NULL;
	}
	return (*this);
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (inventory[i])
		{
			delete inventory[i];
			inventory[i] = NULL;
		}
	}
	for (int i = 0; i < floorcount; i++)
		if (floor[i])
			delete floor[i];
}

str const& Character::getName() const
{
	return this->name;
}

void    Character::equip(AMateria* m)
{
	if (!m)
		return ;
	for (int i = 0; i < 4; i++)
	{
		if (!inventory[i])
		{
			inventory[i] = m;
			return ;
		}
	}
	if (floorcount < 1000)
        floor[floorcount++] = m;
	else
		delete m;
}

void    Character::unequip(int idx)
{
	if (idx < 0 || idx > 3 || !inventory[idx])
		return ;
	if (floorcount < 1000)
	{
		floor[floorcount++] = inventory[idx];
		inventory[idx] = NULL;
	}
}

void    Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx >= 4 || !inventory[idx])
		return ;
	inventory[idx]->use(target);
}
