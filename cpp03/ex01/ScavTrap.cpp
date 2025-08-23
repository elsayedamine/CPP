/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsayed <aelsayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 16:44:12 by aelsayed          #+#    #+#             */
/*   Updated: 2025/08/22 20:05:12 by aelsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp" 

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "Default ScavTrap Constructor Called" << std::endl;
}

ScavTrap::ScavTrap(const str &n) : ClapTrap(n)
{
	setHits(100);
	setEnergy(50);
	setDamage(20);
	std::cout << "ScavTrap \"" << getName() << "\" was created with :" << std::endl;
	std::cout << std::setw(30) << "--------------------" << std::endl;
	std::cout << std::setw(27) << "HP : " << this->getHits() << std::endl;
	std::cout << std::setw(27) << "Energy Points : " << this->getEnergy() << std::endl;
	std::cout << std::setw(27) << "Attack Damage : " << this->getDamage() << std::endl;
	std::cout << std::setw(30) << "--------------------" << std::endl << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &src)
{
	*this = src;
	std::cout << "ScavTrap copy constructed from " << src.getName() << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << this->getName() << " was destroyed." << std::endl;
}

ScavTrap	&ScavTrap::operator=(const ScavTrap& other)
{	
	if (this != &other)
		ClapTrap::operator=(other);
	return (*this);
}

void	ScavTrap::attack(const str &target)
{
	if (getEnergy() > 0 && getHits() > 0)
	{
		std::cout	<< "ScavTrap " << getName() << " fiercely attacks " 
					<< target << ", causing " << getDamage() 
					<< " points of damage!" << std::endl;
		setEnergy(getEnergy() - 1);
	}
	else
		std::cout	<< "ScavTrap " << getName() 
					<< " cannot attack (no energy or HP)!" << std::endl;
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << getName() << " has entered Gate Keeper mode!" << std::endl;
}
