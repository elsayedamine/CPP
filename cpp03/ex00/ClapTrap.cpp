/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsayed <aelsayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 15:02:43 by aelsayed          #+#    #+#             */
/*   Updated: 2025/08/23 11:17:29 by aelsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// constructors
ClapTrap::ClapTrap() : Hits(10), Damage(0), Energy(10)
{
	std::cout << "Default ClapTrap Constructor Called" << std::endl;
}

ClapTrap::ClapTrap(const str &n) : name(n), Hits(10), Damage(0), Energy(10)
{
	std::cout << "ClapTrap \"" << name << "\" was created with :" << std::endl;
	std::cout << std::setw(30) << "--------------------" << std::endl;
	std::cout << std::setw(27) << "HP : " << this->Hits << std::endl;
	std::cout << std::setw(27) << "Energy Points : " << this->Energy << std::endl;
	std::cout << std::setw(27) << "Attack Damage : " << this->Damage << std::endl;
	std::cout << std::setw(30) << "--------------------" << std::endl << std::endl;
}

ClapTrap::ClapTrap(ClapTrap &src)
{
	*this = src;
	std::cout << "ClapTrap copy constructed from " << src.getName() << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << this->name << " was destroyed." << std::endl;
}

ClapTrap	&ClapTrap::operator=(const ClapTrap& other)
{
	if (this != &other)
	{
		this->Damage = other.Damage;
		this->Hits = other.Hits;
		this->Energy = other.Energy;
		this->name = other.name;
	} 
	return (*this);
}

// members
void	ClapTrap::attack(const str &target)
{
	if (this->Hits <= 0 || this->Energy <= 0)
		return (std::cout << "ClapTrap " << this->name << " can't attack!\n", (void)this->Hits);
	std::cout	<< "ClapTrap " << this->name
				<< " attacks " << target
				<< ", causing " << this->Damage
				<< " points of damage!" << std::endl;
	this->Energy--;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->Hits <= 0)
		return (std::cout << "ClapTrap " << this->name << " is dead!\n", (void)amount);
	std::cout	<< "ClapTrap " << this->name
				<< " was attacked causing "
				<< amount
				<< " points of damage!" << std::endl;
	this->Hits -= amount;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->Hits <= 0 || this->Energy <= 0)
		return (std::cout << "ClapTrap " << this->name << " can't be repaired!\n", (void)this->Hits);
	std::cout	<< "ClapTrap " << this->name
				<< " is repairing gaining "
				<< amount
				<< " hit points!" << std::endl;
	this->Hits += amount;
	this->Energy--;
}

// getters/setters
str ClapTrap::getName() const
{
	return this->name;
}
int ClapTrap::getHits() const
{
	return this->Hits;
}
int ClapTrap::getDamage() const
{
	return this->Damage;
}
int ClapTrap::getEnergy() const
{
	return this->Energy;
}
void ClapTrap::setName(const str &n)
{
	name = n;
}
void ClapTrap::setHits(int h)
{
	Hits = h;
}
void ClapTrap::setDamage(int d)
{
	Damage = d;
}
void ClapTrap::setEnergy(int e)
{
	Energy = e;
}
