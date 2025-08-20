/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsayed <aelsayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 15:02:43 by aelsayed          #+#    #+#             */
/*   Updated: 2025/08/20 15:48:44 by aelsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : Hits(10), Damage(0), Energy(10)
{
	std::cout << "Default Constructor Called" << std::endl;
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
