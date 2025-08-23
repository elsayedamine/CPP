/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsayed <aelsayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 12:07:28 by aelsayed          #+#    #+#             */
/*   Updated: 2025/08/23 12:23:38 by aelsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), FragTrap(), ScavTrap()
{
	setHits(FragTrap::getHits());
	setEnergy(ScavTrap::getCopyEnergy());
	setDamage(FragTrap::getCopyDamage());
	std::cout << "Default DiamondTrap Constructor Called" << std::endl;
}

DiamondTrap::DiamondTrap(str n) : ClapTrap(n + "_clap_name"), FragTrap(n), ScavTrap(n)
{
	setHits(FragTrap::getHits());
	setEnergy(ScavTrap::getCopyEnergy());
	setDamage(FragTrap::getCopyDamage());
	this->name = n;

	std::cout << "DiamondTrap \"" << this->name << "\" created with:" << std::endl;
	std::cout << "          --------------------" << std::endl;
	std::cout << "                      HP : " << getHits() << std::endl;
	std::cout << "           Energy Points : " << getEnergy() << std::endl;
	std::cout << "           Attack Damage : " << getDamage() << std::endl;
	std::cout << "          --------------------" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& obj)
	: ClapTrap(obj), FragTrap(obj), ScavTrap(obj)
{
	*this = obj;
	std::cout << "DiamondTrap Copy Constructor Called" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& obj)
{
	if (this != &obj)
		ClapTrap::operator=(obj);
	std::cout << "DiamondTrap Assignation Operator Called" << std::endl;
	return (*this);
}

void DiamondTrap::attack(const str& target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
	std::cout << "I am DiamondTrap \"" << this->name
			  << "\" and my ClapTrap name is \"" << ClapTrap::getName()
			  << "\"" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap Destructor Called" << std::endl;
}
